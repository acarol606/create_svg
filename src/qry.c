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

void dps(FILE *qryFile, char *command, Queue queue) {
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
}

void inp(FILE *qryFile, char *command, Queue queue) {
    printf("--- INICIO INP ---\n");

    char *ptr = strtok(command, " ");
    ptr = strtok(NULL, " ");

    int id;

    id = atoi(ptr);

    insertQueue(queue, id);
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

void sel(char *command, Queue queue, List circleList, List rectangleList, List lineList, List textList, FILE *svgFile) {
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
            insertQueue(queue, id);
            insertSVGAnchor(x, y, svgFile);
        }

        circleCell = getNextCell(circleCell);
    }
        
    while(rectangleCell != NULL) {
        Item rectangle = getCellValue(rectangleCell);

        double x = getXRectangle(rectangle);
        double y = getYRectangle(rectangle);
        int id = getIdRectangle(rectangle);

        if(x >= xSel && x <= width && y >= ySel && y<= height) {
            insertQueue(queue, id);
            insertSVGAnchor(x, y, svgFile);
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
            insertQueue(queue, id);
             insertSVGAnchor(initX, initY, svgFile);
        }

        lineCell = getNextCell(lineCell);
    }

        
    while(textCell != NULL) {
        Item text = getCellValue(textCell);

        double x = getXText(text);
        double y = getYText(text);
        int id = getIdText(text);

        if(x >= xSel && x <= width && y >= ySel && y<= height) {
            insertQueue(queue, id);
            insertSVGAnchor(x, y, svgFile);
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

void queryCommands(FILE *qryFile, int capacity, List circleList, List rectangleList, List lineList, List textList, FILE *svgFile) {
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


        if(strcmp(ptr, "inp")==0) {
            inp(qryFile, str, queue);

        } else if(strcmp(ptr, "pol")==0) {
            pol(str, queue, circleList, rectangleList, lineList, textList, svgFile);

        } else if(strcmp(ptr, "sel")==0) {
            clp(queue);
            sel(str, queue, circleList, rectangleList, lineList, textList, svgFile);

        } else if(strcmp(ptr, "sel+")==0) {
            printf("Sel+ \n");
            sel(str, queue, circleList, rectangleList, lineList, textList, svgFile);

        }  else if(strcmp(ptr, "rmp")==0) {
            rmp(queue);

        }  else if(strcmp(ptr, "clp")==0) {
            clp(queue);

        }
    }
    
     /*    char *eptr;

        if(strcmp(command, "inp")==0) {
            inp(qryFile, command, queue);

        } else if(strcmp(command, "rmp")==0) {
            rmp(queue);

        } else if(strcmp(command, "clp")==0) {
            clp(queue);

        } else if(strcmp(command, "pol")==0) {
            clp(queue);

        }
    }  */

    // makePolygon(queue, circleList, rectangleList, lineList, textList, svgFile);
}