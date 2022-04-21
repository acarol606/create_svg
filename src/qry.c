#include "qry.h"

void inp(FILE *qryFile, char *command, Queue queue) {
    printf("--- INICIO INP ---\n");
    int id;

    fscanf(qryFile, "%s", command);
    printf("%s\n", command);
    id = atoi(command);

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

void sel(FILE *qryFile, char *command, Queue queue, char *eptr, List circleList, List rectangleList, List lineList, List textList, FILE *svgFile) {
    int index = 0;
    double x;
    double y;
    double width;
    double height;

    fscanf(qryFile, "%s", command);
    x = strtod(command, eptr);

    fscanf(qryFile, "%s", command);
    y = strtod(command, eptr);

    fscanf(qryFile, "%s", command);
    width = strtod(command, eptr);

    fscanf(qryFile, "%s", command);
    height = strtod(command, eptr);

    while(hasNext(queue, index)) {
        int id = getData(queue, index);

        Cell circleCell = getFirst(circleList);
        Cell rectangleCell = getFirst(rectangleList);
        Cell lineCell = getFirst(lineList);
        Cell textCell = getFirst(textList);
    
        while(circleCell != NULL) {
            Item circle = getCellValue(circleCell);

            double x = getXCircle(circle);
            double y = getYCircle(circle);


            insertSVGAnchor(y, x, svgFile);

            circleCell = getNextCell(circleCell);
        }
        
        while(rectangleCell != NULL) {
            Item rectangle = getCellValue(rectangleCell);

            double x = getXRectangle(rectangle);
            double y = getYRectangle(rectangle);

            insertSVGAnchor(y, x, svgFile);

            rectangleCell = getNextCell(rectangleCell);
        }
        
        while(lineCell != NULL) {
            Item line = getCellValue(lineCell);

            double initX = getInitXLine(line);
            double initY = getInitYLine(line);

            insertSVGAnchor(initY, initX, svgFile);

            lineCell = getNextCell(lineCell);
        }

        
        while(textCell != NULL) {
            Item text = getCellValue(textCell);

            double x = getXText(text);
            double y = getYText(text);

            insertSVGAnchor(y, x, svgFile);

            textCell = getNextCell(textCell);
        }
        
        index++;
    }
}

void pol(char *command, Queue queue, List circleList, List rectangleList, List lineList, List textList, FILE *qryFile) {
    printf("--- Entrou pol ---\n");

    int id;
    double distance;
    double density;
    char *corb;
    char *corp;

    fscanf(qryFile, "%d", &id);
    fscanf(qryFile, "%lf", &distance);
    fscanf(qryFile, "%lf", &density);

    fscanf(qryFile, "%s", command);
    corb = (char*) malloc(sizeof(char*)+strlen(command)+1);
    strcpy(corb, command);

    fscanf(qryFile, "%s", command);
    corp = (char*) malloc(sizeof(char*)+strlen(command)+1);
    strcpy(corp, command);

    printf("Id: %d\n", id);
    printf("distance: %ls\n", distance);
    printf("density: %ls\n", density);
    printf("corb: %s\n", corb);
    printf("corp: %s\n\n", corp);
}


bool createArchor(int id, int idItem, double x, double y, FILE *svgFile) {
    if(id == idItem) {
        insertSVGAnchor(y, x, svgFile);
        return true;
    } 
    return false;
}

void makePolygon(Queue queue, List circleList, List rectangleList, List lineList, List textList, FILE *svgFile) {
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

	printf("-- Saiu createQueue --\n");

    while(!feof(qryFile)) {
        char *command;
         
        fscanf(qryFile, "%s", command);

        if(strcmp(command, "inp")==0) {
            inp(qryFile, command, queue);

        }
    }
    /* 
        char *eptr;

        if(strcmp(command, "inp")==0) {
            inp(qryFile, command, queue);

        } else if(strcmp(command, "rmp")==0) {
            rmp(queue);

        } else if(strcmp(command, "clp")==0) {
            clp(queue);

        } else if(strcmp(command, "pol")==0) {
            clp(queue);

        } else if(strcmp(command, "sel")==0) {
            sel(qryFile, command, queue, eptr, circleList, rectangleList, lineList, textList, svgFile);

        } 
    } */

    // makePolygon(queue, circleList, rectangleList, lineList, textList, svgFile);
}
