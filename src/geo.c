#include "geo.h"

int buildGeometricForm(FILE *arq, char *outputDir, List circleList, List rectangleList, List lineList, List textList, FILE *svgFile) {
    printf("--- ENTROU buildGeometricForm ---\n");
    while(!feof(arq)) {
        char infos;
        char *eptr;
        fscanf(arq, "%c", &infos);
        if (infos == 'c') {
            Circle circle = createCircle();

            Item item = buildCircle(arq, circle);

            circleList = insertItemInFinal(circleList, item);

        } else if(infos == 'r') {
            Rectangle rectangle = createRectangle();

            Item item = buildRectangle(arq, rectangle);
            
            rectangleList = insertItemInFinal(rectangleList, item);
            
        } else if(infos == 'l') {
            Line line = createLine();

            Item item = buildLine(arq, line);

            lineList = insertItemInFinal(lineList, item);

        } else if(infos == 't') {
            Text text = createText();

            Item item = buildText(arq, text);

            textList = insertItemInFinal(textList, item);
        }
        // printf("--------------------------------\n");
    }

    buildSVG(svgFile, circleList, rectangleList , lineList, textList);

    free(svgFile);
    
    return getSizeList(circleList) + 
           getSizeList(rectangleList) +
           getSizeList(lineList) + 
           getSizeList(textList);
}