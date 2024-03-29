#include "qry.h"

double stringToDouble(char *str) {
    char *eptr;
    return strtod(str, &eptr);
}


bool createArchor(int id, int idItem, double x, double y, FILE *svgFile) {
    if(id == idItem) {
        insertSVGAnchor(y, x, svgFile);
        return true;
    } 
    return false;
}

void makeAnchor(Queue queue, List circleList, List rectangleList, List lineList, List textList, FILE *svgFile) {
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
            }
            id++;
            textCell = getNextCell(textCell);
        }

        id = idAux;
        
        index++;
    }
}

void inp(FILE *svgFile, FILE *txtFile, FILE *qryFile, char *command, Queue queue, List circleList, List rectangleList, List lineList, List textList) {
    char *ptr = strtok(command, " ");
    ptr = strtok(NULL, " ");


    int idInp = atoi(ptr);
        Cell circleCell = getFirst(circleList);
        Cell rectangleCell = getFirst(rectangleList);
        Cell lineCell = getFirst(lineList);
        Cell textCell = getFirst(textList);
    
        while(circleCell != NULL) {
            Item circle = getCellValue(circleCell);

            int idCircle = getIdCircle(circle);


            if(idCircle != idInp) {
                circleCell = getNextCell(circleCell);
            } else {
                double x = getXCircle(circle);
                double y = getYCircle(circle);
                double radius = getRadiusCircle(circle);
                char *corb = getCorBCircle(circle);
                char *corp = getCorPCircle(circle);

                insertQueue(queue, idInp+999);
                insertSVGAnchor(x, y, svgFile);

                fprintf(txtFile, "circulo\n");
                fprintf(txtFile, "âncora em (%lf, %lf)\n", x, y);
                fprintf(txtFile, "raio: %lf\n", radius);
                fprintf(txtFile, "preenchimento: %s", corp);
                fprintf(txtFile, "borda: %s\n\n", corb);
                break;
            }
        }
        
        while(rectangleCell != NULL) {
            Item rectangle = getCellValue(rectangleCell);

            int idRectangle = getIdRectangle(rectangle);

            if(idRectangle != idInp) {

                rectangleCell = getNextCell(rectangleCell);
            } else {

                double x = getXRectangle(rectangle);
                double y = getYRectangle(rectangle);
                double width = getWidthRectangle(rectangle);
                double height = getHeightRectangle(rectangle);
                char *corb = getCorBRectangle(rectangle);
                char *corp = getCorPRectangle(rectangle);

                insertQueue(queue, idInp+999);
                insertSVGAnchor(x, y, svgFile);

                fprintf(txtFile, "retangulo\n");
                fprintf(txtFile, "âncora em (%lf, %lf)\n", x, y);
                fprintf(txtFile, "width: %lf\n", width);
                fprintf(txtFile, "height: %lf\n", height);
                fprintf(txtFile, "preenchimento: %s\n", corp);
                fprintf(txtFile, "borda: %s\n", corb);
                break;
            }
        }
        
        while(lineCell != NULL) {
            Item line = getCellValue(lineCell);

            int idLine = getIdLine(line);

            if(idInp != idLine) {

                lineCell = getNextCell(lineCell);
            } else {
                double x = getInitXLine(line);
                double y = getInitYLine(line);
                double finalX = getFinalXLine(line);
                double finalY = getFinalYLine(line);
                char *color = getColorLine(line);

                insertQueue(queue, idInp+999);
                insertSVGAnchor(x, y, svgFile);

                fprintf(txtFile, "linha\n");
                fprintf(txtFile, "âncora em (%lf, %lf)\n", x, y);
                fprintf(txtFile, "x inicial: %lf\n", x);
                fprintf(txtFile, "y inicial: %lf\n", y);
                fprintf(txtFile, "x final: %lf\n", finalX);
                fprintf(txtFile, "y final: %lf\n", finalY);
                fprintf(txtFile, "cor: %s\n", color);
                break;
            }

        }

        
        while(textCell != NULL) {
            Item text = getCellValue(textCell);

            int idText = getIdText(text);

            if(idInp != idText) {

                textCell = getNextCell(textCell);
            } else {

                double x = getXText(text);
                double y = getYText(text);
                char anchor = getAnchorText(text);
                char *value = getValueText(text);
                char *corb = getCorBText(text);
                char *corp = getCorPText(text);

                if(anchor == 'i') {

                    insertQueue(queue, idInp+999);
                    insertSVGAnchor(x, y, svgFile);
                } else if(anchor == 'm') {

                    insertQueue(queue, idInp+999);
                    insertSVGAnchor(strlen(value)/2, y, svgFile);
                } else {

                    insertQueue(queue, idInp+999);
                    insertSVGAnchor(strlen(value), y, svgFile);

                }

                fprintf(txtFile, "text\n");
                fprintf(txtFile, "âncora: %c\n", anchor);
                fprintf(txtFile, "valor: %s\n", value);
                fprintf(txtFile, "borda: %s\n", corb);
                fprintf(txtFile, "preenchimento: %s\n", corp);
                break;
            }
        }

        makeAnchor(queue, circleList, rectangleList, lineList, textList, svgFile);

}

void rmp(FILE *textFile, Queue queue, List circleList, List rectangleList, List lineList, List textList) {
    printf("--- INICIO RMP ---\n");

    if(queueIsEmpty(queue)) {
        printf("Fila vazia!\n\n");
        return;
    }

    Cell circleCell = getFirst(circleList);
    Cell rectangleCell = getFirst(rectangleList);
    Cell lineCell = getFirst(lineList);
    Cell textCell = getFirst(textList);

    int idQueue = getLast(queue)-999;
    
    while(circleCell != NULL) {
        Item circle = getCellValue(circleCell);

        double x = getXCircle(circle);
        double y = getYCircle(circle);
        int id = getIdCircle(circle);

        if(idQueue == id) {
            fprintf(textFile, "circle\n");
            fprintf(textFile, "x: %lf\n", x);
            fprintf(textFile, "y: %lf\n\n", y);
            break;
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

        if(idQueue == id) {
            fprintf(textFile, "rectangle\n");
            fprintf(textFile, "x: %lf\n", x);
            fprintf(textFile, "y: %lf\n\n", y);
            break;
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

        if(idQueue == id) {
            fprintf(textFile, "line\n");
            fprintf(textFile, "initX: %lf\n", initX);
            fprintf(textFile, "initY: %lf\n", initY);
            fprintf(textFile, "finalX: %lf\n", finalX);
            fprintf(textFile, "finalY: %lf\n\n", finalY);
            break;
        }

        lineCell = getNextCell(lineCell);
    }

        
    while(textCell != NULL) {
        Item text = getCellValue(textCell);

        double x = getXText(text);
        double y = getYText(text);
        char *value = getValueText(text);
        int id = getIdText(text);

        if(idQueue == id) {
            fprintf(textFile, "text\n");
            fprintf(textFile, "x: %lf\n", x);
            fprintf(textFile, "y: %lf\n\n", y);
            break;
        }

        textCell = getNextCell(textCell);
    }

    queueRemove(queue);
}

void clp(Queue queue) {

    if(!queueIsEmpty(queue)) {
        clearQueue(queue);
    }
}

void sel(int indexIds, int *idsSel, FILE *txtFile, char *command, Queue queue, List circleList, List rectangleList, List lineList, List textList, FILE *svgFile) {
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
            insertSVGAnchorSelect(x, y, svgFile);
            idsSel[indexIds] = id;
            indexIds++;
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
            insertSVGAnchorSelect(x, y, svgFile);
            idsSel[indexIds] = id;
            indexIds++;
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
            insertSVGAnchorSelect(initX, initY, svgFile);
            idsSel[indexIds] = id;
            indexIds++;
        }

        lineCell = getNextCell(lineCell);
    }

        
    while(textCell != NULL) {
        Item text = getCellValue(textCell);

        double x = getXText(text);
        double y = getYText(text);
        char *value = getValueText(text);
        int id = getIdText(text);

        if(x >= xSel && x <= width && y >= ySel && y<= height && strlen(value) >= xSel && strlen(value) <= ySel) {
            fprintf(txtFile, "%d: texto\n", id);
            insertQueue(queue, id);
            insertSVGAnchorSelect(x, y, svgFile);
            idsSel[indexIds] = id;
            indexIds++;
        }

        textCell = getNextCell(textCell);
    }
}

void linkAnchor(double firstX, double firstY,int index, double initX, double initY, int nextAnchorId, Queue queue, List circleList, List rectangleList, List lineList, List textList, char *color, int idAnchor, FILE *svgFile) {
    double finalX, finalY;


        Cell circleCell = getFirst(circleList);
        Cell rectangleCell = getFirst(rectangleList);
        Cell lineCell = getFirst(lineList);
        Cell textCell = getFirst(textList);
    
        while(circleCell != NULL) {
            Item circle = getCellValue(circleCell);

            int idCircle = getIdCircle(circle);
            double x = getXCircle(circle);
            double y = getYCircle(circle);

            if(idCircle == nextAnchorId) {
                finalX = x;
                finalY = y;
                break;
            }

            circleCell = getNextCell(circleCell);
        }
        
        while(rectangleCell != NULL) {
            Item rectangle = getCellValue(rectangleCell);

            int idRectangle = getIdRectangle(rectangle);
            double x = getXRectangle(rectangle);
            double y = getYRectangle(rectangle);

            if(idRectangle == nextAnchorId) {
                finalX = x;
                finalY = y;
            }
            rectangleCell = getNextCell(rectangleCell);
        }
        
        while(lineCell != NULL) {
            Item line = getCellValue(lineCell);

            int idLine = getIdLine(line);
            double x = getInitXLine(line);
            double y = getInitYLine(line);

            if(idLine == nextAnchorId) {
                finalX = x;
                finalY = y;
            }
            lineCell = getNextCell(lineCell);

        }
        
        while(textCell != NULL) {
            Item text = getCellValue(textCell);

            int idText = getIdText(text);
            double x = getXText(text);
            double y = getYText(text);

            if(idText == nextAnchorId) {
                finalX = x;
                finalY = y;
            }
            textCell = getNextCell(textCell);

        }
        createSVGLine(idAnchor, initX, initY, finalX, finalY, color, svgFile);
        if(index+1 == getSizeQueue(queue)) {

            createSVGLine(idAnchor, finalX, finalY, firstX, firstY, color, svgFile);

        }
}

void pol(char *command, Queue queue, List circleList, List rectangleList, List lineList, List textList, FILE *svgFile) {
    printf("--- Entrou pol ---\n");

    char *ptr = strtok(command, " ");
    ptr = strtok(NULL, " ");

    int idPol;
    double distance;
    double density;
    char *corb;
    char *corp;
    char *eptr;

    idPol = atoi(ptr);
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

    printf("Id: %d\n", idPol);
    printf("distance: %lf\n", distance);
    printf("density: %lf\n", density);
    printf("corb: %s\n", corb);
    printf("corp: %s\n\n", corp);



    int index = 0;
    int firstItem = -1;
    double firstX, firstY;
    while(hasNext(queue, index)) {

        int id = getData(queue, index);
        int auxIndex = index+1;

        Cell circleCell = getFirst(circleList);
        Cell rectangleCell = getFirst(rectangleList);
        Cell lineCell = getFirst(lineList);
        Cell textCell = getFirst(textList);

        while(circleCell != NULL) {
            Item circle = getCellValue(circleCell);

            int idCircle = getIdCircle(circle);
            double x = getXCircle(circle);
            double y = getYCircle(circle);

            if(idCircle == (id-999)) {

                if(firstItem == -1) {
                    firstItem = idCircle;
                    firstX = x;
                    firstY = y;
                }
                // printf("index: %d - auxIndex: %d\n", index, auxIndex);
                int nextAnchor = getData(queue, auxIndex);
                if(hasNext(queue, index)) {
                    linkAnchor(firstX, firstY, auxIndex, x, y, nextAnchor-999, queue, circleList, rectangleList, lineList, textList, corb, idPol, svgFile);
                    idPol++;
                    break;
                }

            }

            circleCell = getNextCell(circleCell);

        }
        
        while(rectangleCell != NULL) {
            Item rectangle = getCellValue(rectangleCell);

            int idRectangle = getIdRectangle(rectangle);
            double x = getXRectangle(rectangle);
            double y = getYRectangle(rectangle);

            if(idRectangle == (id-999)) {
                if(firstItem == -1) {
                    firstItem = idRectangle;
                    firstX = x;
                    firstY = y;
                }
                // printf("index: %d - auxIndex: %d\n", index, auxIndex);
                int nextAnchor = getData(queue, auxIndex);
                if(hasNext(queue, index)) {
                    linkAnchor(firstX, firstY, auxIndex, x, y, nextAnchor-999, queue, circleList, rectangleList, lineList, textList, corb, idPol, svgFile);
                    idPol++;
                    break;
                }
            }

            rectangleCell = getNextCell(rectangleCell);
        }
        
        while(lineCell != NULL) {
            Item line = getCellValue(lineCell);

            int idLine = getIdLine(line);
            double x = getInitXLine(line);
            double y = getInitYLine(line);

            if(idLine == (id-999)) {
                if(firstItem == -1) {
                    firstItem = idLine;
                    firstX = x;
                    firstY = y;
                }
                // printf("index: %d - auxIndex: %d\n", index, auxIndex);
                int nextAnchor = getData(queue, auxIndex);
                if(hasNext(queue, index)) {
                    linkAnchor(firstX, firstY, auxIndex, x, y, nextAnchor-999, queue, circleList, rectangleList, lineList, textList, corb, idPol, svgFile);
                    idPol++;
                    break;
                }
            }
            lineCell = getNextCell(lineCell);
        }

        
        while(textCell != NULL) {
            Item text = getCellValue(textCell);

            int idText = getIdText(text);
            char a = getAnchorText(text);
            char *value = getValueText(text);
            double x = getXText(text);
            double y = getYText(text);


            if(idText == (id-999)) {
                if(a == 'm') {
                    x = strlen(value)/2;
                } else if (a == 'f') {
                    x = strlen(value);
                }

                if(firstItem == -1) {
                    firstItem = idText;
                    firstX = x;
                    firstY = y;
                }
                // printf("index: %d - auxIndex: %d\n", index, auxIndex);
                int nextAnchor = getData(queue, auxIndex);
                if(hasNext(queue, index)) {
                    linkAnchor(firstX, firstY, auxIndex, x, y, nextAnchor-999, queue, circleList, rectangleList, lineList, textList, corb, idPol, svgFile);
                    idPol++;
                    break;
                }
            }
            textCell = getNextCell(textCell);
        }
        
        index++;
    }
    
}

/* void ups(char *command, int indexIds, int *idsSel, FILE *svgFile, Queue queue, List circleList, List rectangleList, List lineList, List textList) {
    

    char *ptr = strtok(command, " ");
    ptr = strtok(NULL, " ");

    char *corb = (char*) malloc(sizeof(char*)+strlen(ptr)+1);
    strcpy(corb, ptr);
    ptr = strtok(NULL, " ");

    char *corp = (char*) malloc(sizeof(char*)+strlen(ptr)+1);
    strcpy(corp, ptr);
    ptr = strtok(NULL, " ");

    double dx = strtod(ptr);
    ptr = strtok(NULL, " ");

    double dy = strtod(ptr);
    ptr = strtok(NULL, " ");

    int n = atoi(ptr);



    Cell circleCell = getFirst(circleList);
    Cell rectangleCell = getFirst(rectangleList);
    Cell lineCell = getFirst(lineList);
    Cell textCell = getFirst(textList);
    
    while(circleCell != NULL) {
        Item circle = getCellValue(circleCell);

        double x = getXCircle(circle);
        double y = getYCircle(circle);
        int id = getIdCircle(circle);

        if(indexIds >= 0 && idsSel[indexIds] == id) {
            
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
        }

        lineCell = getNextCell(lineCell);
    }

        
    while(textCell != NULL) {
        Item text = getCellValue(textCell);

        double x = getXText(text);
        double y = getYText(text);
        int id = getIdText(text);

        if(x >= xSel && x <= width && y >= ySel && y<= height) {
        }

        textCell = getNextCell(textCell);
    }
} */

void queryCommands(FILE *newSVG, FILE *readSVG, FILE *txtFile, FILE *qryFile, int capacity, List circleList, List rectangleList, List lineList, List textList, FILE *svgFile) {
    printf("--- Entrou queryCommands ---\n");

    Queue queue = createQueue(capacity);

    char str[200];
    char idCommand[200];
    int *idsSel = malloc(sizeof(int)*capacity);
    int indexIds = 0;

    while(!feof(qryFile)) {
        if(fgets(str, 200, qryFile)== NULL) break; 

        strcpy(idCommand, str);

        char *ptr = strtok(idCommand, " ");

        printf("PTR: |%s|\n\n", ptr);


        fprintf(txtFile, "[*] %s", str);
        if(strcmp(ptr, "inp")==0) {
            inp(svgFile, txtFile, qryFile, str, queue, circleList, rectangleList, lineList, textList);

        } else if(strcmp(ptr, "pol")==0) {
            pol(str, queue, circleList, rectangleList, lineList, textList, svgFile);

        } else if(strcmp(ptr, "sel")==0) {
            clp(queue);
            indexIds = 0;
            free(idsSel);
            idsSel = malloc(sizeof(int)*capacity);
            sel(indexIds, idsSel, txtFile, str, queue, circleList, rectangleList, lineList, textList, svgFile);

        } else if(strcmp(ptr, "sel+")==0) {
            printf("Sel+ \n");
            sel(indexIds, idsSel, txtFile, str, queue, circleList, rectangleList, lineList, textList, svgFile);

        }  else if(strcmp(ptr, "rmp")==0) {
            rmp(txtFile, queue, circleList, rectangleList, lineList, textList);

        }  else if(strcmp(ptr, "clp")==0) {
            clp(queue);

        } else if(strcmp(ptr, "dps")==0) {
            dps(txtFile, str, queue, circleList, rectangleList, lineList, textList, svgFile);

        } else if(strcmp(ptr, "dels")==0) {
            dels(txtFile, newSVG, readSVG, circleList, rectangleList, lineList, textList, idsSel, capacity);
        }
    }
}

void dels(FILE *textFile, FILE *newSVG, FILE *readSVG, List circleList, List rectangleList, List lineList, List textList, int *idsSel, int capacity) {
    printf("--- Entrou dels --- \n");
    fprintf(newSVG, "<svg xmlns:svg=\"http://www.w3.org/2000/svg\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">");
    int indexIds = 0;
    int t = 1;
    int i;
    for(i=0; i<capacity; i++) {
        if(idsSel[i] != 0) {
            // printf("T: %d\n", idsSel[i]);
        }
    }
    Cell circleCell = getFirst(circleList);
    Cell rectangleCell = getFirst(rectangleList);
    Cell lineCell = getFirst(lineList);
    Cell textCell = getFirst(textList);
    
    while(circleCell != NULL) {
        Item circle = getCellValue(circleCell);

        double x = getXCircle(circle);
        double y = getYCircle(circle);
        int id = getIdCircle(circle);
        char *corb = getCorBCircle(circle);
        char *corp = getCorPCircle(circle);
        double radius = getRadiusCircle(circle);

        if(idsSel[indexIds] != id) {
            lerSVG(newSVG, readSVG, 'c', id, corb, corp, radius, 0.0, 0.0, x, y, 0.0, 0.0, 'n', "na", t);
        } else {
            fprintf(textFile, "\ncircle\n");
            fprintf(textFile, "x: %lf\n", x);
            fprintf(textFile, "y: %lf\n", y);
            fprintf(textFile, "radius: %lf\n", radius);
            fprintf(textFile, "corb: %s\n", corb);
            fprintf(textFile, "corp: %s\n\n", corp);
            indexIds++;
        }

        circleCell = getNextCell(circleCell);
    }

    indexIds = 0;
        
    while(rectangleCell != NULL) {
        Item rectangle = getCellValue(rectangleCell);

        double x = getXRectangle(rectangle);
        double y = getYRectangle(rectangle);
        double widthRec = getWidthRectangle(rectangle);
        double heightRec = getHeightRectangle(rectangle);
        int id = getIdRectangle(rectangle);
        char *corb = getCorBRectangle(rectangle);
        char *corp = getCorPRectangle(rectangle);

        if(indexIds <= capacity && idsSel[indexIds] == id) {
            lerSVG(newSVG, readSVG, 'r', id, corb, corp, 0.0, heightRec, widthRec, x, y, 0.0, 0.0, 'n', "na", t);
        
        } else {
            fprintf(textFile, "\nrectangle\n");
            fprintf(textFile, "id: %d\n", id);
            fprintf(textFile, "x: %lf\n", x);
            fprintf(textFile, "y: %lf\n", y);
            fprintf(textFile, "width: %lf\n", widthRec);
            fprintf(textFile, "height: %lf\n", heightRec);
            fprintf(textFile, "corb: %s\n", corb);
            fprintf(textFile, "corp: %s\n\n", corp);
            indexIds++;
        }

        rectangleCell = getNextCell(rectangleCell);
    }

    indexIds = 0;
        
    while(lineCell != NULL) {
        Item line = getCellValue(lineCell);

        double initX = getInitXLine(line);
        double initY = getInitYLine(line);
        double finalX = getFinalXLine(line);
        double finalY = getFinalYLine(line);
        int id = getIdLine(line);
        char *corb = getColorLine(line);

        if(idsSel[indexIds] != id) {
            lerSVG(newSVG, readSVG, 'l', id, corb, "", 0.0, 0.0, 0.0, initX, initY, finalX, finalY, 'n', "na", t);
            
        } else {
            fprintf(textFile, "\nline\n");
            fprintf(textFile, "id: %d\n", id);
            fprintf(textFile, "initX: %lf\n", initX);
            fprintf(textFile, "initY: %lf\n", initY);
            fprintf(textFile, "finalX: %lf\n", finalX);
            fprintf(textFile, "finalY: %lf\n", finalY);
            fprintf(textFile, "color: %s\n\n", corb);
            indexIds += 1;
        }

        lineCell = getNextCell(lineCell);
    }

    indexIds = 0;
        
    while(textCell != NULL) {
        Item text = getCellValue(textCell);

        double x = getXText(text);
        double y = getYText(text);
        char anchor = getAnchorText(text);
        char *value = getValueText(text);
        char *corb = getCorBText(text);
        char *corp = getCorPText(text);
        int id = getIdText(text);


        if(indexIds <= capacity && idsSel[indexIds] == id) {
            lerSVG(newSVG, readSVG, 't', id, corb, corp, 0.0, 0.0, 0.0, x, y, 0.0, 0.0, anchor, value, t);
        
        } else {
            fprintf(textFile, "text\n");
            fprintf(textFile, "x: %lf\n", x);
            fprintf(textFile, "y: %lf\n", y);
            fprintf(textFile, "ancora: %c\n", anchor);
            fprintf(textFile, "corb: %s\n", corb);
            fprintf(textFile, "corp: %s\n", corp);
            fprintf(textFile, "valor: %s\n\n", value);
            indexIds++;
        }

        textCell = getNextCell(textCell);
    }
}

void lerSVG(FILE *newSVG, FILE *readSVG, char type, int id, char*corb, char *corp, double radius, double height, double width, double x, double y, double x2, double y2, char anchor, char*value, int t) {
    printf("--- Entrou lerSVG --- \n");

    char str[300];
    char newStr[300];
    char *tagSVG = malloc(sizeof(char) * 300);
    while(!feof(readSVG)) {

        if(fgets(str, 300, readSVG)== NULL) break; 
        strtok(str, "\n");
        
        if(type == 'c') {
            sprintf(tagSVG, "\t<circle id=\"%d\" style=\"fill:%s;fill-opacity:0.5;stroke:%s\" r=\"%lf\" cy=\"%lf\" cx=\"%lf\"/>", id, corb, corp, radius, y, x);

        } else if(type == 'r') {
            sprintf(tagSVG, "\t<rect id=\"%d\" style=\"fill:%s;fill-opacity:0.5;stroke:%s\" height=\"%lf\" width=\"%lf\" y=\"%lf\" x=\"%lf\" />", id, corb, corp, height, width, y, x);

        } else if(type == 'l') {
            sprintf(tagSVG, "\t<line id=\"%d\" x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\" fill-opacity=\"50\" />", id, x, y, x2, y2, corb);

        } else if(type == 't') {
            sprintf(tagSVG, "\t<text id=\"%d\" x=\"%lf\" y=\"%lf\" text-anchor=\"%c\" stroke=\"%s\" fill=\"%s\" fill-opacity=\"50\" >\"%s\"</text>", id, x, y, anchor, corb, corp, value);
        }
        

        if(!(strcmp(tagSVG, str)==0)) {
            printf("tag 1: %s\n", tagSVG);
            strcat(tagSVG, "\n");
            fprintf(newSVG, tagSVG);
            fflush(newSVG);
            break;
        } else {
            printf("Vezes: %d\n", t);
            t++;

        }
    }
}