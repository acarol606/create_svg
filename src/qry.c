#include "qry.h"

double stringToDouble(char *str) {
    char *eptr;
    return strtod(str, &eptr);
}

void generateSelection(double x, double y, double width, double height, FILE *svgFile) {
    createSVGLine(9999, x, y, x, y+height, "red", svgFile);
    createSVGLine(9999, x, y, x+width, y, "red", svgFile);
    createSVGLine(9999, x+width, y, x+width, y+height, "red", svgFile);
    createSVGLine(9999, x, y+height, x+width, y+height, "red", svgFile);
}

void dps(FILE *textFile, char *command, Queue queue, List circleList, List rectangleList, List lineList, List textList, FILE *svgFile) {
    printf("--- INICIO dps ---\n");

    char *ptr = strtok(command, " ");
    ptr = strtok(NULL, " ");

    int id = atoi(ptr);
    ptr = strtok(NULL, " ");

    double dx = stringToDouble(ptr);
    ptr = strtok(NULL, " ");

    double dy = stringToDouble(ptr);
    ptr = strtok(NULL, " ");

    char *corb = (char*) malloc(sizeof(char*)+strlen(ptr)+1);
    strcpy(corb, ptr);
    ptr = strtok(NULL, " ");

    char *corp = (char*) malloc(sizeof(char*)+strlen(ptr)+1);
    strcpy(corp, ptr);

    printf("--- DPS:\n");
    printf("Id: %d\n", id);
    printf("dx: %lf\n", dx);
    printf("dy: %lf\n", dy);
    printf("Corb: %s\n", corb);
    printf("Corp: %s\n", corp);

    int index = 0;
    int idAux = id;

    while(hasNext(queue, index)) {
        int idItem = getData(queue, index);

        Cell circleCell = getFirst(circleList);
        Cell rectangleCell = getFirst(rectangleList);
        Cell lineCell = getFirst(lineList);
        Cell textCell = getFirst(textList);
    
        while(circleCell != NULL) {
            Item circle = getCellValue(circleCell);

            int idCircle = getIdCircle(circle);
            double x = getXCircle(circle);
            double y = getYCircle(circle);
            double radius = getRadiusCircle(circle);

            if(idCircle == idItem) {
                printf("Circle\n");
                fprintf(textFile, "circle\n");
                fprintf(textFile, "id: %d\n", id);
                fprintf(textFile, "x: %lf\n", dx+x);
                fprintf(textFile, "y: %lf\n", dy+y);
                fprintf(textFile, "raio: %lf\n", radius);
                fprintf(textFile, "borda: %lf\n", corb);
                fprintf(textFile, "preenchimento: %lf\n", corp);
                createSVGCircle(id, corb, corp, radius, dy+y, dx+x, svgFile);
            }
            id++;


            circleCell = getNextCell(circleCell);
        }

        id = idAux;
        
        while(rectangleCell != NULL) {
            Item rectangle = getCellValue(rectangleCell);

            int idRectangle = getIdRectangle(rectangle);
            double x = getXRectangle(rectangle);
            double y = getYRectangle(rectangle);
            double width = getWidthRectangle(rectangle);
            double height = getHeightRectangle(rectangle);

            if(idRectangle == idItem) {
                printf("Rectangle\n");
                fprintf(textFile, "\nretangulo\n");
                fprintf(textFile, "id: %d\n", id);
                fprintf(textFile, "x: %lf\n", dx+x);
                fprintf(textFile, "y: %lf\n", dy+y);
                fprintf(textFile, "width: %lf\n", width);
                fprintf(textFile, "height: %lf\n", height);
                fprintf(textFile, "borda: %lf\n", corb);
                fprintf(textFile, "preenchimento: %lf\n", corp);
                createSVGRectangle(id, corb, corp, width, height, dy+y, dx+x, svgFile);
                // rectangleCell = getNextCell(rectangleCell);
            }
            id++;
            rectangleCell = getNextCell(rectangleCell);
        }

        id = idAux;
        
        while(lineCell != NULL) {
            Item line = getCellValue(lineCell);

            int idLine = getIdLine(line);
            double initX = getInitXLine(line);
            double initY = getInitYLine(line);
            double finalX = getFinalXLine(line);
            double finalY = getFinalYLine(line);

            if(idLine == idItem) {
                printf("Line \n");
                fprintf(textFile, "\nlinha\n");
                fprintf(textFile, "id: %d\n", id);
                fprintf(textFile, "x: %lf\n", dx+initX);
                fprintf(textFile, "y: %lf\n", dy+initY);
                fprintf(textFile, "x final: %lf\n", dx+finalX);
                fprintf(textFile, "y final: %lf\n", dy+finalY);
                fprintf(textFile, "cor: %lf\n", corb);
                createSVGLine(id, dx+initX, dy+initY, dx+finalX, dy+finalY, corb, svgFile);
                id++;
            }
            lineCell = getNextCell(lineCell);
        }

        id = idAux;

        
        while(textCell != NULL) {
            Item text = getCellValue(textCell);

            int idText = getIdText(text);
            double x = getXText(text);
            double y = getYText(text);
            char anchor = getAnchorText(text);
            char *value = getValueText(text);

            if(idText == idItem) {
                printf("Text\n");
                fprintf(textFile, "\ntext\n");
                fprintf(textFile, "id: %d\n", id);
                fprintf(textFile, "x: %lf\n", x);
                fprintf(textFile, "y: %lf\n", y);
                fprintf(textFile, "ancora: %lf\n", anchor);
                fprintf(textFile, "borda: %s\n", corb);
                fprintf(textFile, "preenchimento: %lf\n", corp);
                createSVGText(id, dx+x, dy+y, anchor, corb, corp, value, svgFile);
                // textCell = getNextCell(textCell);
            }
            id++;
            textCell = getNextCell(textCell);
        }

        id = idAux;
        
        index++;
    }
}

void inp(FILE *txtFile, FILE *qryFile, char *command, Queue queue, List circleList, List rectangleList, List lineList, List textList) {
    printf("--- INICIO INP ---\n");

    char *ptr = strtok(command, " ");
    ptr = strtok(NULL, " ");

    int id;

    id = atoi(ptr);

    insertQueue(queue, id);

    int index = 0;

    while(hasNext(queue, index)) {
        int id = getData(queue, index);

        Cell circleCell = getFirst(circleList);
        Cell rectangleCell = getFirst(rectangleList);
        Cell lineCell = getFirst(lineList);
        Cell textCell = getFirst(textList);
    
        while(circleCell != NULL) {
            Item circle = getCellValue(circleCell);

            int idCircle = getIdCircle(circle);

            if(idCircle != id) {
                circleCell = getNextCell(circleCell);
            } else {
                double x = getXCircle(circle);
                double y = getYCircle(circle);
                double radius = getRadiusCircle(circle);
                char *corb = getCorBCircle(circle);
                char *corp = getCorPCircle(circle);

                fprintf(txtFile, "círculo");
                fprintf(txtFile, "âncora em (%lf, %lf)", x, y);
                fprintf(txtFile, "raio: %lf", radius);
                fprintf(txtFile, "preenchimento: %s", corp);
                fprintf(txtFile, "borda: %s\n", corb);
                break;
            }
        }
        
        while(rectangleCell != NULL) {
            Item rectangle = getCellValue(rectangleCell);

            int idRectangle = getIdRectangle(rectangle);

            if(idRectangle != id) {

                rectangleCell = getNextCell(rectangleCell);
            } else {

                double x = getXRectangle(rectangle);
                double y = getYRectangle(rectangle);
                double width = getWidthRectangle(rectangle);
                double height = getHeightRectangle(rectangle);
                char *corb = getCorBRectangle(rectangle);
                char *corp = getCorPRectangle(rectangle);

                fprintf(txtFile, "retangulo");
                fprintf(txtFile, "âncora em (%lf, %lf)", x, y);
                fprintf(txtFile, "width: %lf", width);
                fprintf(txtFile, "height: %lf", height);
                fprintf(txtFile, "preenchimento: %s", corp);
                fprintf(txtFile, "borda: %s\n", corb);
                break;
            }
        }
        
        while(lineCell != NULL) {
            Item line = getCellValue(lineCell);

            int idLine = getIdLine(line);

            if(id != idLine) {

                lineCell = getNextCell(lineCell);
            } else {

                double x = getInitXLine(line);
                double y = getInitYLine(line);
                double finalX = getFinalXLine(line);
                double finalY = getFinalYLine(line);
                char *color = getColorLine(line);

                fprintf(txtFile, "linha");
                fprintf(txtFile, "âncora em (%lf, %lf)", x, y);
                fprintf(txtFile, "x inicial: %lf", x);
                fprintf(txtFile, "y inicial: %lf", y);
                fprintf(txtFile, "x final: %s", finalX);
                fprintf(txtFile, "y final: %s\n", finalY);
                break;
            }

        }

        
        while(textCell != NULL) {
            Item text = getCellValue(textCell);

            int idText = getIdText(text);

            if(id != idText) {

                textCell = getNextCell(textCell);
            } else {

                double x = getXText(text);
                double y = getYText(text);
                char anchor = getAnchorText(text);
                char *value = getValueText(text);
                char *corb = getCorBText(text);
                char *corp = getCorPText(text);

                fprintf(txtFile, "text");
                fprintf(txtFile, "âncora: %c", anchor);
                fprintf(txtFile, "valor: %s", value);
                fprintf(txtFile, "borda: %s", corb);
                fprintf(txtFile, "preenchimento: %s", corp);
                break;
            }
        }
        
        index++;
    }
}

void rmp(Queue queue) {
    printf("--- INICIO RMP ---\n");

    if(queueIsEmpty(queue)) {
        printf("Fila vazia!\n\n");
        return;
    }

    queueRemove(queue);
}

void clp(Queue queue) {

    if(queueIsEmpty(queue)) {
        printf("Fila vazia!\n\n");
        return;
    }

    clearQueue(queue);
}

void sel(FILE *txtFile, char *command, Queue queue, List circleList, List rectangleList, List lineList, List textList, FILE *svgFile) {
    printf("--- Entrou sel ---\n");
    double xSel;
    double ySel;
    double width;
    double height;

    char *ptr = strtok(command, " ");
    ptr = strtok(NULL, " ");

    xSel = stringToDouble(ptr);
    ptr = strtok(NULL, " ");

    ySel = stringToDouble(ptr);
    ptr = strtok(NULL, " ");

    width = stringToDouble(ptr);
    ptr = strtok(NULL, " ");

    height = stringToDouble(ptr);

    printf("X: %lf\n", xSel);
    printf("Y: %lf\n", ySel);
    printf("Width: %lf\n", width);
    printf("Height: %lf\n", height);

    generateSelection(xSel, ySel, width, height, svgFile);

    Cell circleCell = getFirst(circleList);
    Cell rectangleCell = getFirst(rectangleList);
    Cell lineCell = getFirst(lineList);
    Cell textCell = getFirst(textList);
    
    while(circleCell != NULL) {
        Item circle = getCellValue(circleCell);

        double x = getXCircle(circle);
        double y = getYCircle(circle);
        int id = getIdCircle(circle);

        if(x >= xSel && x <= width && y >= ySel && y<= height) {
            fprintf(txtFile, "%d: circulo\n", id);
            insertQueue(queue, id);
            insertSVGAnchor(x, y, svgFile);
            insertSVGAnchorSelect(x, y, svgFile);
        }

        circleCell = getNextCell(circleCell);
    }
        
    while(rectangleCell != NULL) {
        Item rectangle = getCellValue(rectangleCell);

        double x = getXRectangle(rectangle);
        double y = getYRectangle(rectangle);
        double widthRec = getWidthRectangle(rectangle);
        double heightRec = getHeightRectangle(rectangle);
        int id = getIdRectangle(rectangle);

        if(x >= xSel && x <= width && y >= ySel && y<= height && 
          widthRec <= xSel && widthRec >= width && heightRec <= ySel && heightRec >= height) {
            fprintf(txtFile, "%d: retangulo\n", id);
            insertQueue(queue, id);
            insertSVGAnchor(x, y, svgFile);
            insertSVGAnchorSelect(x, y, svgFile);
        }

        rectangleCell = getNextCell(rectangleCell);
    }
        
    while(lineCell != NULL) {
        Item line = getCellValue(lineCell);

        double initX = getInitXLine(line);
        double initY = getInitYLine(line);
        double finalX = getFinalXLine(line);
        double finalY = getFinalYLine(line);
        int id = getIdLine(line);

        if(initX >= xSel && initX <= width && initY >= ySel && initY<= height && 
            finalX >= xSel && finalX <= width && finalY >= ySel && finalY<= height) {
            fprintf(txtFile, "%d: linha\n", id);
            insertQueue(queue, id);
            insertSVGAnchor(initX, initY, svgFile);
            insertSVGAnchorSelect(initX, initY, svgFile);
        }

        lineCell = getNextCell(lineCell);
    }

        
    while(textCell != NULL) {
        Item text = getCellValue(textCell);

        double x = getXText(text);
        double y = getYText(text);
        int id = getIdText(text);

        if(x >= xSel && x <= width && y >= ySel && y<= height) {
            fprintf(txtFile, "%d: texto\n", id);
            insertQueue(queue, id);
            insertSVGAnchor(x, y, svgFile);
            insertSVGAnchorSelect(x, y, svgFile);
        }

        textCell = getNextCell(textCell);
    }
}

void pol(char *command, Queue queue, List circleList, List rectangleList, List lineList, List textList, FILE *svgFile) {
    printf("--- Entrou pol ---\n");

    char *ptr = strtok(command, " ");
    ptr = strtok(NULL, " ");

    int id;
    double distance;
    double density;
    char *corb;
    char *corp;
    char *eptr;

    id = atoi(ptr);
    ptr = strtok(NULL, " ");

    distance = stringToDouble(ptr);
    ptr = strtok(NULL, " ");

    density = stringToDouble(ptr);
    ptr = strtok(NULL, " ");

    corb = (char*) malloc(sizeof(char*)+strlen(ptr)+1);
    strcpy(corb, ptr);
    ptr = strtok(NULL, " ");

    corp = (char*) malloc(sizeof(char*)+strlen(ptr)+1);
    strcpy(corp, ptr);

    printf("Id: %d\n", id);
    printf("distance: %lf\n", distance);
    printf("density: %lf\n", density);
    printf("corb: %s\n", corb);
    printf("corp: %s\n\n", corp);

    makeAnchor(queue, circleList, rectangleList, lineList, textList, svgFile);
}



bool createArchor(int id, int idItem, double x, double y, FILE *svgFile) {
    if(id == idItem) {
        insertSVGAnchor(y, x, svgFile);
        return true;
    } 
    return false;
}

void makeAnchor(Queue queue, List circleList, List rectangleList, List lineList, List textList, FILE *svgFile) {
    printf("--- Entrou makeAnchor ---\n\n");
    int index = 0;

    while(hasNext(queue, index)) {
        int id = getData(queue, index);

        Cell circleCell = getFirst(circleList);
        Cell rectangleCell = getFirst(rectangleList);
        Cell lineCell = getFirst(lineList);
        Cell textCell = getFirst(textList);
    
        while(circleCell != NULL) {
            Item circle = getCellValue(circleCell);

            int idCircle = getIdCircle(circle);
            double x = getXCircle(circle);
            double y = getYCircle(circle);

            if(!createArchor(id, idCircle, x, y, svgFile)) {
                circleCell = getNextCell(circleCell);
            } else {
                break;
            }
        }
        
        while(rectangleCell != NULL) {
            Item rectangle = getCellValue(rectangleCell);

            int idRectangle = getIdRectangle(rectangle);
            double x = getXRectangle(rectangle);
            double y = getYRectangle(rectangle);

            if(!createArchor(id, idRectangle, x, y, svgFile)) {

                rectangleCell = getNextCell(rectangleCell);
            } else {
                break;
            }
        }
        
        while(lineCell != NULL) {
            Item line = getCellValue(lineCell);

            int idLine = getIdLine(line);
            double x = getInitXLine(line);
            double y = getInitYLine(line);

            if(!createArchor(id, idLine, x, y, svgFile)) {

                lineCell = getNextCell(lineCell);
            } else {
                break;
            }

        }

        
        while(textCell != NULL) {
            Item text = getCellValue(textCell);

            int idText = getIdText(text);
            double x = getXText(text);
            double y = getYText(text);

            if(!createArchor(id, idText, x, y, svgFile)) {

                textCell = getNextCell(textCell);
            } else {
                break;
            }
        }
        
        index++;
    }
}

void queryCommands(FILE *txtFile, FILE *qryFile, int capacity, List circleList, List rectangleList, List lineList, List textList, FILE *svgFile) {
    printf("--- Entrou queryCommands ---\n");

    Queue queue = createQueue(capacity);

    char str[200];
    char idCommand[200];

    while(!feof(qryFile)) {
        char *command;
        if(fgets(str, 200, qryFile)== NULL) break; 

        strcpy(idCommand, str);

        char *ptr = strtok(idCommand, " ");

        printf("PTR: %s\n\n", ptr);


        fprintf(txtFile, "[*] %s", str);
        if(strcmp(ptr, "inp")==0) {
            inp(txtFile, qryFile, str, queue, circleList, rectangleList, lineList, textList);

        } else if(strcmp(ptr, "pol")==0) {
            pol(str, queue, circleList, rectangleList, lineList, textList, svgFile);

        } else if(strcmp(ptr, "sel")==0) {
            clp(queue);
            sel(txtFile, str, queue, circleList, rectangleList, lineList, textList, svgFile);

        } else if(strcmp(ptr, "sel+")==0) {
            printf("Sel+ \n");
            sel(txtFile, str, queue, circleList, rectangleList, lineList, textList, svgFile);

        }  else if(strcmp(ptr, "rmp")==0) {
            rmp(squeue);

        }  else if(strcmp(ptr, "clp")==0) {
            clp(queue);

        } else if(strcmp(ptr, "dps")==0) {
            dps(txtFile, str, queue, circleList, rectangleList, lineList, textList, svgFile);
        }
    }
}