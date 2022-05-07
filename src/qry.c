#include "qry.h"

double stringToDouble(char* str) {
    char* eptr;
    return strtod(str, &eptr);
}


bool createArchor(int id, int idItem, double x, double y, FILE* svgFile) {
    if (id == idItem) {
        insertSVGAnchor(y, x, svgFile);
        return true;
    }
    return false;
}

void makeAnchor(Queue queue, List circleList, List rectangleList, List lineList, List textList, FILE* svgFile) {
    int index = 0;

    while (hasNext(queue, index)) {
        int id = getData(queue, index);

        Cell circleCell = getFirst(circleList);
        Cell rectangleCell = getFirst(rectangleList);
        Cell lineCell = getFirst(lineList);
        Cell textCell = getFirst(textList);

        while (circleCell != NULL) {
            Item circle = getCellValue(circleCell);

            int idCircle = getIdCircle(circle);
            double x = getXCircle(circle);
            double y = getYCircle(circle);

            if (!createArchor(id, idCircle, x, y, svgFile)) {
                circleCell = getNextCell(circleCell);
            }
            else {
                break;
            }
        }

        while (rectangleCell != NULL) {
            Item rectangle = getCellValue(rectangleCell);

            int idRectangle = getIdRectangle(rectangle);
            double x = getXRectangle(rectangle);
            double y = getYRectangle(rectangle);

            if (!createArchor(id, idRectangle, x, y, svgFile)) {

                rectangleCell = getNextCell(rectangleCell);
            }
            else {
                break;
            }
        }

        while (lineCell != NULL) {
            Item line = getCellValue(lineCell);

            int idLine = getIdLine(line);
            double x = getInitXLine(line);
            double y = getInitYLine(line);

            if (!createArchor(id, idLine, x, y, svgFile)) {

                lineCell = getNextCell(lineCell);
            }
            else {
                break;
            }

        }


        while (textCell != NULL) {
            Item text = getCellValue(textCell);

            int idText = getIdText(text);
            double x = getXText(text);
            double y = getYText(text);

            if (!createArchor(id, idText, x, y, svgFile)) {

                textCell = getNextCell(textCell);
            }
            else {
                break;
            }
        }

        index++;
    }
}

void generateSelection(double x, double y, double width, double height, FILE* svgFile) {
    createSVGLine(9999, x, y, x, y + height, "red", svgFile);
    createSVGLine(9999, x, y, x + width, y, "red", svgFile);
    createSVGLine(9999, x + width, y, x + width, y + height, "red", svgFile);
    createSVGLine(9999, x, y + height, x + width, y + height, "red", svgFile);
}

void dps(FILE* textFile, char* command, Queue queue, List circleList, List rectangleList, List lineList, List textList, FILE* svgFile) {
    printf("--- INICIO dps ---\n");

    char* ptr = strtok(command, " ");
    ptr = strtok(NULL, " ");

    int id = atoi(ptr);
    ptr = strtok(NULL, " ");

    double dx = stringToDouble(ptr);
    ptr = strtok(NULL, " ");

    double dy = stringToDouble(ptr);
    ptr = strtok(NULL, " ");

    char* corb = (char*)malloc(sizeof(char*) + strlen(ptr) + 1);
    strcpy(corb, ptr);
    ptr = strtok(NULL, " ");

    char* corp = (char*)malloc(sizeof(char*) + strlen(ptr) + 1);
    strcpy(corp, ptr);

    printf("--- DPS:\n");
    printf("Id: %d\n", id);
    printf("dx: %lf\n", dx);
    printf("dy: %lf\n", dy);
    printf("Corb: %s\n", corb);
    printf("Corp: %s\n", corp);

    int index = 0;

    getSizeList(circleList, "circulos");
    getSizeList(rectangleList, "retangulos");
    getSizeList(lineList, "linhas");
    getSizeList(textList, "textos");

    while (hasNext(queue, index)) {
        int idItem = getData(queue, index);
        Cell circleCell = getFirst(circleList);
        Cell rectangleCell = getFirst(rectangleList);
        Cell lineCell = getFirst(lineList);
        Cell textCell = getFirst(textList);

        while (circleCell != NULL) {
            Item circle = getCellValue(circleCell);

            int idCircle = getIdCircle(circle);
            double x = getXCircle(circle);
            double y = getYCircle(circle);
            double radius = getRadiusCircle(circle);

            if (idCircle == idItem) {
                printf("Circle\n");
                fprintf(textFile, "circle\n");
                fprintf(textFile, "id: %d\n", id);
                fprintf(textFile, "x: %lf\n", dx + x);
                fprintf(textFile, "y: %lf\n", dy + y);
                fprintf(textFile, "raio: %lf\n", radius);
                fprintf(textFile, "borda: %s\n", corb);
                fprintf(textFile, "preenchimento: %s\n", corp);
                createSVGCircle(id, corb, corp, radius, dy + y, dx + x, svgFile);
                printf("aqui circ\n\n");
                id++;
            }


            circleCell = getNextCell(circleCell);
        }

        while (rectangleCell != NULL) {
            Item rectangle = getCellValue(rectangleCell);

            int idRectangle = getIdRectangle(rectangle);
            double x = getXRectangle(rectangle);
            double y = getYRectangle(rectangle);
            double width = getWidthRectangle(rectangle);
            double height = getHeightRectangle(rectangle);

            if (idRectangle == idItem) {
                printf("Rectangle\n");
                fprintf(textFile, "\nretangulo\n");
                fprintf(textFile, "id: %d\n", id);
                fprintf(textFile, "x: %lf\n", dx + x);
                fprintf(textFile, "y: %lf\n", dy + y);
                fprintf(textFile, "width: %lf\n", width);
                fprintf(textFile, "height: %lf\n", height);
                fprintf(textFile, "borda: %s\n", corb);
                fprintf(textFile, "preenchimento: %s\n", corp);
                createSVGRectangle(id, corb, corp, width, height, dy + y, dx + x, svgFile);
                id++;
            }
            rectangleCell = getNextCell(rectangleCell);
        }

        while (lineCell != NULL) {
            Item line = getCellValue(lineCell);

            int idLine = getIdLine(line);
            double initX = getInitXLine(line);
            double initY = getInitYLine(line);
            double finalX = getFinalXLine(line);
            double finalY = getFinalYLine(line);

            if (idLine == idItem) {
                printf("Line \n");
                fprintf(textFile, "\nlinha\n");
                fprintf(textFile, "id: %d\n", id);
                fprintf(textFile, "x: %lf\n", dx + initX);
                fprintf(textFile, "y: %lf\n", dy + initY);
                fprintf(textFile, "x final: %lf\n", dx + finalX);
                fprintf(textFile, "y final: %lf\n", dy + finalY);
                fprintf(textFile, "cor: %s\n", corb);
                createSVGLine(id, dx + initX, dy + initY, dx + finalX, dy + finalY, corb, svgFile);
                id++;
            }
            lineCell = getNextCell(lineCell);
        }


        while (textCell != NULL) {
            Item text = getCellValue(textCell);

            int idText = getIdText(text);
            double x = getXText(text);
            double y = getYText(text);
            char anchor = getAnchorText(text);
            char* value = getValueText(text);

            if (idText == idItem) {
                printf("Text\n");
                fprintf(textFile, "\ntext\n");
                fprintf(textFile, "id: %d\n", id);
                fprintf(textFile, "x: %lf\n", x);
                fprintf(textFile, "y: %lf\n", y);
                fprintf(textFile, "ancora: %c\n", anchor);
                fprintf(textFile, "borda: %s\n", corb);
                fprintf(textFile, "preenchimento: %s\n", corp);
                createSVGText(id, dx + x, dy + y, anchor, corb, corp, value, svgFile);
                id++;
            }
            textCell = getNextCell(textCell);
        }

        index++;
    }
}

void inp(FILE* svgFile, FILE* txtFile, FILE* qryFile, char* command, Queue queue, List circleList, List rectangleList, List lineList, List textList) {
    printf("--- Entrou inp ---\n");
    char* ptr = strtok(command, " ");
    ptr = strtok(NULL, " ");


    int idInp = atoi(ptr);
    Cell circleCell = getFirst(circleList);
    Cell rectangleCell = getFirst(rectangleList);
    Cell lineCell = getFirst(lineList);
    Cell textCell = getFirst(textList);


    while (circleCell != NULL) {
        Item circle = getCellValue(circleCell);

        int idCircle = getIdCircle(circle);


        if (idCircle == idInp) {
            printf("IdInp: %d\n", idCircle);
            double x = getXCircle(circle);
            double y = getYCircle(circle);
            double radius = getRadiusCircle(circle);
            char* corb = getCorBCircle(circle);
            char* corp = getCorPCircle(circle);

            insertQueue(queue, idInp);
            insertSVGAnchor(x, y, svgFile);

            fprintf(txtFile, "circulo\n");
            fprintf(txtFile, "âncora em (%lf, %lf)\n", x, y);
            fprintf(txtFile, "raio: %lf\n", radius);
            fprintf(txtFile, "preenchimento: %s", corp);
            fprintf(txtFile, "borda: %s\n\n", corb);
            break;
        }
        circleCell = getNextCell(circleCell);
    }

    while (rectangleCell != NULL) {
        Item rectangle = getCellValue(rectangleCell);

        int idRectangle = getIdRectangle(rectangle);

        if (idRectangle == idInp) {


            printf("IdInp: %d\n", idRectangle);
            double x = getXRectangle(rectangle);
            double y = getYRectangle(rectangle);
            double width = getWidthRectangle(rectangle);
            double height = getHeightRectangle(rectangle);
            char* corb = getCorBRectangle(rectangle);
            char* corp = getCorPRectangle(rectangle);

            insertQueue(queue, idInp);
            insertSVGAnchor(x, y, svgFile);

            fprintf(txtFile, "retangulo\n");
            fprintf(txtFile, "âncora em (%lf, %lf)\n", x, y);
            fprintf(txtFile, "width: %lf\n", width);
            fprintf(txtFile, "height: %lf\n", height);
            fprintf(txtFile, "preenchimento: %s\n", corp);
            fprintf(txtFile, "borda: %s\n", corb);
            break;
        }
        rectangleCell = getNextCell(rectangleCell);
    }

    while (lineCell != NULL) {
        Item line = getCellValue(lineCell);

        int idLine = getIdLine(line);

        if (idInp == idLine) {

            printf("IdInp: %d\n", idLine);
            double x = getInitXLine(line);
            double y = getInitYLine(line);
            double finalX = getFinalXLine(line);
            double finalY = getFinalYLine(line);
            char* color = getColorLine(line);

            insertQueue(queue, idInp);
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

        lineCell = getNextCell(lineCell);
    }


    while (textCell != NULL) {
        Item text = getCellValue(textCell);

        int idText = getIdText(text);

        if (idInp == idText) {

            printf("IdInp: %d\n", idText);
            double x = getXText(text);
            double y = getYText(text);
            char anchor = getAnchorText(text);
            char* value = getValueText(text);
            char* corb = getCorBText(text);
            char* corp = getCorPText(text);

            if (anchor == 'f') {

                printf("Ancora: %c\n", anchor);
                x = strlen(value);
            }
            else if (anchor == 'm') {

                printf("Ancora: %c\n", anchor);
                x = strlen(value)/2;
            }

            insertQueue(queue, idInp);
            insertSVGAnchor(x, y, svgFile);

            fprintf(txtFile, "text\n");
            fprintf(txtFile, "âncora: %c\n", anchor);
            fprintf(txtFile, "valor: %s", value);
            fprintf(txtFile, "borda: %s\n", corb);
            fprintf(txtFile, "preenchimento: %s\n\n", corp);
            break;
        }
        textCell = getNextCell(textCell);
    }
}

void rmp(Queue queue, List circleList, List rectangleList, List lineList, List textList, FILE* txtFile) {
    printf("--- INICIO RMP ---\n");

    if (!queueIsEmpty(queue)) {
        int lastIndex = getLast(queue);
        queueRemove(queue);
        Cell circleCell = getFirst(circleList);
        Cell rectangleCell = getFirst(rectangleList);
        Cell lineCell = getFirst(lineList);
        Cell textCell = getFirst(textList);

        while (circleCell != NULL) {
            Item circle = getCellValue(circleCell);

            int idCircle = getIdCircle(circle);


            if (idCircle != lastIndex) {
                circleCell = getNextCell(circleCell);
            }
            else {
                double x = getXCircle(circle);
                double y = getYCircle(circle);

                fprintf(txtFile, "âncora em (%lf, %lf)\n", x, y);
                break;
            }
        }

        while (rectangleCell != NULL) {
            Item rectangle = getCellValue(rectangleCell);

            int idRectangle = getIdRectangle(rectangle);

            if (idRectangle != lastIndex) {

                rectangleCell = getNextCell(rectangleCell);
            }
            else {

                double x = getXRectangle(rectangle);
                double y = getYRectangle(rectangle);

                fprintf(txtFile, "âncora em (%lf, %lf)\n", x, y);
                break;
            }
        }

        while (lineCell != NULL) {
            Item line = getCellValue(lineCell);

            int idLine = getIdLine(line);

            if (idLine != lastIndex) {

                lineCell = getNextCell(lineCell);
            }
            else {
                double x = getInitXLine(line);
                double y = getInitYLine(line);

                fprintf(txtFile, "âncora em (%lf, %lf)\n", x, y);
                break;
            }

        }


        while (textCell != NULL) {
            Item text = getCellValue(textCell);

            int idText = getIdText(text);

            if (lastIndex != idText) {

                textCell = getNextCell(textCell);
            }
            else {

                double x = getXText(text);
                double y = getYText(text);
                char anchor = getAnchorText(text);
                char* value = getValueText(text);
                char* corb = getCorBText(text);
                char* corp = getCorPText(text);

                if (anchor == 'i') {

                }
                else if (anchor == 'm') {

                    x = strlen(value) / 2;
                }
                else {

                    x = strlen(value);
                }

                fprintf(txtFile, "âncora: %c (x: %lf, y: %lf)\n", anchor, x, y);
                break;
            }
        }
    }

}

void clp(Queue queue) {

    if (queueIsEmpty(queue)) {
        printf("Fila vazia!\n\n");
        return;
    }

    clearQueue(queue);
}

void sel(FILE* txtFile, char* command, Queue queue, List circleList, List rectangleList, List lineList, List textList, FILE* svgFile, char* type, int qtdSel) {
    printf("--- Entrou sel ---\n");
    double xSel;
    double ySel;
    double width;
    double height;

    char* ptr = strtok(command, " ");
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

    while (circleCell != NULL) {
        Item circle = getCellValue(circleCell);

        double x = getXCircle(circle);
        double y = getYCircle(circle);
        int id = getIdCircle(circle);

        if (x >= xSel && x <= width && y >= ySel && y <= height) {
            fprintf(txtFile, "%d: circulo\n", id);
            insertQueue(queue, id);
            insertSVGAnchorSelect(x, y, svgFile);
            if (strcmp(type, "sel+") == 0) {
                qtdSel++;
                fprintf(txtFile, "Quantidade figuras selecionadas por esse comando: %d\n", qtdSel);
                fprintf(txtFile, "Quantidade total de figuras: %d\n", getSizeQueue(queue));
            }
        }

        circleCell = getNextCell(circleCell);
    }

    while (rectangleCell != NULL) {
        Item rectangle = getCellValue(rectangleCell);

        double x = getXRectangle(rectangle);
        double y = getYRectangle(rectangle);
        double widthRec = getWidthRectangle(rectangle);
        double heightRec = getHeightRectangle(rectangle);
        int id = getIdRectangle(rectangle);

        if (x >= xSel && x <= width && y >= ySel && y <= height &&
            widthRec <= xSel && widthRec >= width && heightRec <= ySel && heightRec >= height) {
            fprintf(txtFile, "%d: retangulo\n", id);
            insertQueue(queue, id);
            insertSVGAnchorSelect(x, y, svgFile);
            if (strcmp(type, "sel+") == 0) {
                qtdSel++;
                fprintf(txtFile, "Quantidade figuras selecionadas por esse comando: %d\n", qtdSel);
                fprintf(txtFile, "Quantidade total de figuras: %d\n", getSizeQueue(queue));
            }
        }

        rectangleCell = getNextCell(rectangleCell);
    }

    while (lineCell != NULL) {
        Item line = getCellValue(lineCell);

        double initX = getInitXLine(line);
        double initY = getInitYLine(line);
        double finalX = getFinalXLine(line);
        double finalY = getFinalYLine(line);
        int id = getIdLine(line);

        if (initX >= xSel && initX <= width && initY >= ySel && initY <= height &&
            finalX >= xSel && finalX <= width && finalY >= ySel && finalY <= height) {
            fprintf(txtFile, "%d: linha\n", id);
            insertQueue(queue, id);
            insertSVGAnchorSelect(initX, initY, svgFile);
            if (strcmp(type, "sel+") == 0) {
                qtdSel++;
                fprintf(txtFile, "Quantidade figuras selecionadas por esse comando: %d\n", qtdSel);
                fprintf(txtFile, "Quantidade total de figuras: %d\n", getSizeQueue(queue));
            }
        }

        lineCell = getNextCell(lineCell);
    }


    while (textCell != NULL) {
        Item text = getCellValue(textCell);

        double x = getXText(text);
        double y = getYText(text);
        char* value = getValueText(text);
        int id = getIdText(text);

        if (x >= xSel && x <= width && y >= ySel && y <= height && strlen(value) >= xSel && strlen(value) <= ySel) {
            fprintf(txtFile, "%d: texto\n", id);
            insertQueue(queue, id);
            insertSVGAnchorSelect(x, y, svgFile);
            if (strcmp(type, "sel+") == 0) {
                qtdSel++;
                fprintf(txtFile, "Quantidade figuras selecionadas por esse comando: %d\n", qtdSel);
                fprintf(txtFile, "Quantidade total de figuras: %d\n", getSizeQueue(queue));
            }
        }

        textCell = getNextCell(textCell);
    }
}

void linkAnchor(double firstX, double firstY, int index, double initX, double initY, int nextAnchorId, Queue queue, List circleList, List rectangleList, List lineList, List textList, char* color, int idAnchor, FILE* svgFile) {
    double finalX, finalY;


    Cell circleCell = getFirst(circleList);
    Cell rectangleCell = getFirst(rectangleList);
    Cell lineCell = getFirst(lineList);
    Cell textCell = getFirst(textList);

    while (circleCell != NULL) {
        Item circle = getCellValue(circleCell);

        int idCircle = getIdCircle(circle);
        double x = getXCircle(circle);
        double y = getYCircle(circle);

        if (idCircle == nextAnchorId) {
            finalX = x;
            finalY = y;
            break;
        }

        circleCell = getNextCell(circleCell);
    }

    while (rectangleCell != NULL) {
        Item rectangle = getCellValue(rectangleCell);

        int idRectangle = getIdRectangle(rectangle);
        double x = getXRectangle(rectangle);
        double y = getYRectangle(rectangle);

        if (idRectangle == nextAnchorId) {
            finalX = x;
            finalY = y;
        }
        rectangleCell = getNextCell(rectangleCell);
    }

    while (lineCell != NULL) {
        Item line = getCellValue(lineCell);

        int idLine = getIdLine(line);
        double x = getInitXLine(line);
        double y = getInitYLine(line);

        if (idLine == nextAnchorId) {
            finalX = x;
            finalY = y;
        }
        lineCell = getNextCell(lineCell);

    }

    while (textCell != NULL) {
        Item text = getCellValue(textCell);

        int idText = getIdText(text);
        double x = getXText(text);
        double y = getYText(text);

        if (idText == nextAnchorId) {
            finalX = x;
            finalY = y;
        }
        textCell = getNextCell(textCell);

    }

    createSVGLine(idAnchor, initX, initY, finalX, finalY, color, svgFile);
    if (index + 1 == getSizeQueue(queue)) {

        createSVGLine(idAnchor, finalX, finalY, firstX, firstY, color, svgFile);

    }
}

void pol(char* command, Queue queue, List circleList, List rectangleList, List lineList, List textList, FILE* svgFile, bool teste) {
    printf("--- Entrou pol ---\n");

    char* ptr = strtok(command, " ");
    ptr = strtok(NULL, " ");

    int idPol;
    double distance;
    double density;
    char* corb;
    char* corp;
    char* eptr;

    idPol = atoi(ptr);
    ptr = strtok(NULL, " ");

    distance = stringToDouble(ptr);
    ptr = strtok(NULL, " ");

    density = stringToDouble(ptr);
    ptr = strtok(NULL, " ");

    corb = (char*)malloc(sizeof(char*) + strlen(ptr) + 1);
    strcpy(corb, ptr);
    ptr = strtok(NULL, " ");

    corp = (char*)malloc(sizeof(char*) + strlen(ptr) + 1);
    strcpy(corp, ptr);

    printf("Id: %d\n", idPol);
    printf("distance: %lf\n", distance);
    printf("density: %lf\n", density);
    printf("corb: %s\n", corb);
    printf("corp: %s\n\n", corp);



    int index = 0;
    int firstItem = -1;
    double firstX, firstY;
    while (hasNext(queue, index)) {
        // printf("Size queue: %d\n", getSizeQueue(queue));
        int idItem = getData(queue, index);
        int auxIndex = index + 1;

        Cell circleCell = getFirst(circleList);
        Cell rectangleCell = getFirst(rectangleList);
        Cell lineCell = getFirst(lineList);
        Cell textCell = getFirst(textList);

        while (circleCell != NULL) {
            Item circle = getCellValue(circleCell);

            int idCircle = getIdCircle(circle);
            double x = getXCircle(circle);
            double y = getYCircle(circle);

            if (idCircle == (idItem)) {

                if (firstItem == -1) {
                    firstItem = idCircle;
                    firstX = x;
                    firstY = y;
                }
                // printf("index: %d - auxIndex: %d\n", index, auxIndex);
                int nextAnchor = getData(queue, auxIndex);
                if (hasNext(queue, index)) {
                    linkAnchor(firstX, firstY, auxIndex, x, y, nextAnchor, queue, circleList, rectangleList, lineList, textList, corb, idPol, svgFile);
                    idPol++;
                    break;
                }

            }

            circleCell = getNextCell(circleCell);

        }

        while (rectangleCell != NULL) {
            Item rectangle = getCellValue(rectangleCell);

            int idRectangle = getIdRectangle(rectangle);
            double x = getXRectangle(rectangle);
            double y = getYRectangle(rectangle);

            if (idRectangle == (idItem)) {
                if (firstItem == -1) {
                    firstItem = idRectangle;
                    firstX = x;
                    firstY = y;
                }
                // printf("index: %d - auxIndex: %d\n", index, auxIndex);
                int nextAnchor = getData(queue, auxIndex);
                if (hasNext(queue, index)) {
                    linkAnchor(firstX, firstY, auxIndex, x, y, nextAnchor, queue, circleList, rectangleList, lineList, textList, corb, idPol, svgFile);
                    idPol++;
                    break;
                }
            }

            rectangleCell = getNextCell(rectangleCell);
        }

        while (lineCell != NULL) {
            Item line = getCellValue(lineCell);

            int idLine = getIdLine(line);
            double x = getInitXLine(line);
            double y = getInitYLine(line);

            if (idLine == (idItem)) {
                if (firstItem == -1) {
                    firstItem = idLine;
                    firstX = x;
                    firstY = y;
                }
                int nextAnchor = getData(queue, auxIndex);
                if (hasNext(queue, index)) {
                    linkAnchor(firstX, firstY, auxIndex, x, y, nextAnchor, queue, circleList, rectangleList, lineList, textList, corb, idPol, svgFile);
                    idPol++;
                    break;
                }
            }

            lineCell = getNextCell(lineCell);
        }

        while (textCell != NULL) {
            Item text = getCellValue(textCell);

            int idText = getIdText(text);
            char a = getAnchorText(text);
            char* value = getValueText(text);
            double x = getXText(text);
            double y = getYText(text);


            if (idText == (idItem)) {
                if (a == 'm') {
                    x = strlen(value) / 2;
                }
                else if (a == 'f') {
                    x = strlen(value);
                }

                if (firstItem == -1) {
                    firstItem = idText;
                    firstX = x;
                    firstY = y;
                }
                // printf("index: %d - auxIndex: %d\n", index, auxIndex);
                int nextAnchor = getData(queue, auxIndex);
                if (hasNext(queue, index)) {
                    linkAnchor(firstX, firstY, auxIndex, x, y, nextAnchor, queue, circleList, rectangleList, lineList, textList, corb, idPol, svgFile);
                    idPol++;
                    break;
                }
            }
            textCell = getNextCell(textCell);
        }

        index++;
    }

}


void queryCommands(FILE* txtFile, FILE* qryFile, int capacity, List circleList, List rectangleList, List lineList, List textList, FILE* svgFile) {
    printf("--- Entrou queryCommands ---\n");

    Queue queue = createQueue(capacity);

    char str[200];
    char idCommand[200];
    int qtdSel = 0;
    int count = 0;

    while (!feof(qryFile)) {
        char* command;
        if (fgets(str, 200, qryFile) == NULL) break;

        strcpy(idCommand, str);

        char* ptr = strtok(idCommand, " ");

        if (ptr[strlen(ptr) - 1] == '\n') {
            ptr[strlen(ptr) - 1] = '\0';
        }

        printf("PTR: |%s|\n\n", ptr);


        fprintf(txtFile, "[*] %s", str);
        if (strcmp(ptr, "inp") == 0) {
            inp(svgFile, txtFile, qryFile, str, queue, circleList, rectangleList, lineList, textList);

        }
        else if (strcmp(ptr, "pol") == 0) {
            pol(str, queue, circleList, rectangleList, lineList, textList, svgFile, count == 1);
            count++;
        }
        else if (strcmp(ptr, "sel") == 0) {
            sel(txtFile, str, queue, circleList, rectangleList, lineList, textList, svgFile, "sel", qtdSel);

        }
        else if (strcmp(ptr, "sel+") == 0) {
            clp(queue);
            sel(txtFile, str, queue, circleList, rectangleList, lineList, textList, svgFile, "sel+", qtdSel);

        }
        else if (strcmp(ptr, "rmp") == 0) {
            rmp(queue, circleList, rectangleList, lineList, textList, txtFile);

        }
        else if (strcmp(ptr, "clp") == 0) {
            clp(queue);

        }
        else if (strcmp(ptr, "dps") == 0) {
            dps(txtFile, str, queue, circleList, rectangleList, lineList, textList, svgFile);
        }
    }
}