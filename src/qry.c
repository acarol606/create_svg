#include "qry.h"

double stringToDouble(char *str) {
    char *eptr;
    return strtod(str, &eptr);
}

bool createArchor(int id, int idItem, double x, double y, FILE *svgFile) {
    if(id == idItem) {
        printf("Id: %d\nidItem: %d\nx: %lf\ny: %lf\n", id, idItem, x, y);
        insertSVGAnchor(x, y, svgFile);
        return true;
    } 
    return false;
}

void generateSelection(double x, double y, double width, double height, FILE *svgFile) {
    createSVGLine(9999, x, y, x, y+height, "red", svgFile);
    createSVGLine(9999, x, y, x+width, y, "red", svgFile);
    createSVGLine(9999, x+width, y, x+width, y+height, "red", svgFile);
    createSVGLine(9999, x, y+height, x+width, y+height, "red", svgFile);
}

void dps(char *command, Queue queue, List circleList, List rectangleList, List lineList, List textList, FILE *svgFile) {
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

            if(idCircle == idItem) {
                printf("Circle\n");
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

            if(idRectangle == idItem) {
                printf("Rectangle\n");
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

            if(idText == idItem) {
                printf("Text\n");
                // textCell = getNextCell(textCell);
            }
            id++;
            textCell = getNextCell(textCell);
        }

        id = idAux;
        
        index++;
    }
}

void inp(FILE *qryFile, char *command, Queue queue, List circleList, List rectangleList, List lineList, List textList, double *anchorX, double *anchorY, int *idItem, int indexAnchor) {
    char *ptr = strtok(command, " ");
    ptr = strtok(NULL, " ");

    int idInp;

    idInp = atoi(ptr);

    insertQueue(queue, idInp);

    Cell circleCell = getFirst(circleList);
    Cell rectangleCell = getFirst(rectangleList);
    Cell lineCell = getFirst(lineList);
    Cell textCell = getFirst(textList);
    
    while(circleCell != NULL) {
        Item circle = getCellValue(circleCell);

        double x = getXCircle(circle);
        double y = getYCircle(circle);
        int id = getIdCircle(circle);

        if(id == idInp) {
            // insertQueue(queue, idInp, x, y);
            anchorX[indexAnchor] = x;
            anchorY[indexAnchor] = y;
            idItem[indexAnchor] = id;
        }

        circleCell = getNextCell(circleCell);
    }
        
    while(rectangleCell != NULL) {
        Item rectangle = getCellValue(rectangleCell);

        double x = getXRectangle(rectangle);
        double y = getYRectangle(rectangle);
        int id = getIdRectangle(rectangle);

        if(id == idInp) {
            // insertQueue(queue, idInp, x, y);
            anchorX[indexAnchor] = x;
            anchorY[indexAnchor] = y;
            idItem[indexAnchor] = id;
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

        if(id == idInp) {
            if(initX < finalX || (initX == finalX && initY < finalY)) {
                // insertQueue(queue, idInp, initX, initY);
                anchorX[indexAnchor] = initX;
                anchorY[indexAnchor] = initY;
                idItem[indexAnchor] = idInp;

            } else {
                // insertQueue(queue, idInp, finalX, finalY);
                anchorX[indexAnchor] = finalX;
                anchorY[indexAnchor] = finalY;
                idItem[indexAnchor] = idInp;

            }
        }

        lineCell = getNextCell(lineCell);
    }

        
    while(textCell != NULL) {
        Item text = getCellValue(textCell);

        double x = getXText(text);
        double y = getYText(text);
        char anchor = getAnchorText(text);
        char *value = getValueText(text);

        if(anchor == 'i') {
            // insertQueue(queue, idInp, x, y);
            anchorX[indexAnchor] = x;
            anchorY[indexAnchor] = y;
            idItem[indexAnchor] = idInp;

        } else if(anchor == 'm') {

            // insertQueue(queue, idInp, (strlen(text)-x)/2, y);
            anchorX[indexAnchor] = (strlen(value)-x)/2;
            anchorY[indexAnchor] = y;
            idItem[indexAnchor] = idInp;

        } else {

            // insertQueue(queue, idInp, strlen(text), y);
            anchorX[indexAnchor] = strlen(value);
            anchorY[indexAnchor] = y;
            idItem[indexAnchor] = idInp;
        }

        textCell = getNextCell(textCell);
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
            insertSVGAnchorSelect(x, y, svgFile);
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
            insertQueue(queue, id);
            insertSVGAnchor(x, y, svgFile);
            insertSVGAnchorSelect(x, y, svgFile);
        }

        textCell = getNextCell(textCell);
    }
}

void pol(char *command, Queue queue, List circleList, List rectangleList, List lineList, List textList, FILE *svgFile, double *anchorX, double *anchorY, int *idItem, int indexAnchor) {
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

    makeAnchor(anchorX, anchorY, idItem, indexAnchor, circleList, rectangleList, lineList, textList, svgFile);

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

            if(idCircle == id && anchorX[indexAnchor] == idCircle) {
                if(indexAnchor+1 == sizeof(anchorX)) {
                    break;
                } else {
                    createSVGLine(idPol, anchorX[indexAnchor], anchorY[indexAnchor], anchorX[indexAnchor+1], anchorY[indexAnchor+1], corb, svgFile);
                    indexAnchor++;
                }
            }
        }
        
        while(rectangleCell != NULL) {
            Item rectangle = getCellValue(rectangleCell);

            int idRectangle = getIdRectangle(rectangle);
            double x = getXRectangle(rectangle);
            double y = getYRectangle(rectangle);

            if(idRectangle == id && anchorX[indexAnchor] == idRectangle) {
                if(indexAnchor+1 == sizeof(anchorX)) {
                    break;
                } else {
                    createSVGLine(idPol, anchorX[indexAnchor], anchorY[indexAnchor], anchorX[indexAnchor+1], anchorY[indexAnchor+1], corb, svgFile);
                    indexAnchor++;
                }
            }
        }
        
        while(lineCell != NULL) {
            Item line = getCellValue(lineCell);

            int idLine = getIdLine(line);
            double x = getInitXLine(line);
            double y = getInitYLine(line);

            if(idLine == id && anchorX[indexAnchor] == idLine) {
                if(indexAnchor+1 == sizeof(anchorX)) {
                    break;
                } else {
                    createSVGLine(idPol, anchorX[indexAnchor], anchorY[indexAnchor], anchorX[indexAnchor+1], anchorY[indexAnchor+1], corb, svgFile);
                    indexAnchor++;
                }
            }

        }

        
        while(textCell != NULL) {
            Item text = getCellValue(textCell);

            int idText = getIdText(text);
            double x = getXText(text);
            double y = getYText(text);

            if(idText == id && anchorX[indexAnchor] == idText) {
                if(indexAnchor+1 == sizeof(anchorX)) {
                    break;
                } else {
                    createSVGLine(idPol, anchorX[indexAnchor], anchorY[indexAnchor], anchorX[indexAnchor+1], anchorY[indexAnchor+1], corb, svgFile);
                    indexAnchor++;
                }
            }
        }
        
        index++;
    }
}

void makeAnchor(double *anchorX, double *anchorY, int *idItem, int indexAnchor, List circleList, List rectangleList, List lineList, List textList, FILE *svgFile) {
    printf("--- Entrou makeAnchor ---\n");
    
    Cell circleCell = getFirst(circleList);
    Cell rectangleCell = getFirst(rectangleList);
    Cell lineCell = getFirst(lineList);
    Cell textCell = getFirst(textList);

        printf("For--- %d\n", idItem[indexAnchor]);
    
        while(circleCell != NULL) {
            Item circle = getCellValue(circleCell);

            int idCircle = getIdCircle(circle);
            double x = getXCircle(circle);
            double y = getYCircle(circle);

            if(!createArchor(idItem[indexAnchor], idCircle, x, y, svgFile)) {
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

            if(!createArchor(idItem[indexAnchor], idRectangle, x, y, svgFile)) {

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

            if(!createArchor(idItem[indexAnchor], idLine, x, y, svgFile)) {

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

            if(!createArchor(idItem[indexAnchor], idText, x, y, svgFile)) {

                textCell = getNextCell(textCell);
            } else {
                break;
            }
        }
}

void queryCommands(FILE *qryFile, int capacity, List circleList, List rectangleList, List lineList, List textList, FILE *svgFile) {
    printf("--- Entrou queryCommands ---\n");

    Queue queue = createQueue(capacity);

    int queueTam = getCapacity(queue);
    double *anchorX = (double *) malloc(sizeof(double) * queueTam);
    double *anchorY = (double *) malloc(sizeof(double) * queueTam);
    int *idItem = (int *) malloc(sizeof(int) * queueTam);
    char str[200];
    char idCommand[200];
    int indexAnchorInp = 0;
    int indexAnchorPol = 0;

    while(!feof(qryFile)) {
        char *command;
        if(fgets(str, 200, qryFile)== NULL) break; 

        strcpy(idCommand, str);


        char *ptr = strtok(idCommand, " ");

        if(strcmp(ptr, "inp")==0) {
            inp(qryFile, str, queue, circleList, rectangleList, lineList, textList, anchorX, anchorY, idItem, indexAnchorInp);

            indexAnchorInp++;
        } else if(strcmp(ptr, "pol")==0) {
            pol(str, queue, circleList, rectangleList, lineList, textList, svgFile, anchorX, anchorY, idItem, indexAnchorPol);
            
            indexAnchorInp++;
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

        } /* else if(strcmp(ptr, "dps")==0) {
            dps(str, queue, circleList, rectangleList, lineList, textList, svgFile);
        } */
    }
    /* int i;
    for (i=0;i<indexAnchor; i++) {
        printf("Id: %d\n", idItem[i]);
    } */
}