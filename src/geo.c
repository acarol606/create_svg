#include "geo.h"

int buildGeometricForm(FILE *svgFileClean, FILE *arq, char *outputDir, List circleList, List rectangleList, List lineList, List textList, FILE *svgFile) {
    printf("--- ENTROU buildGeometricForm ---\n");

    char str[200];
    char idGeo[200];
    int count = 0;
    while(!feof(arq)) {

        if(fgets(str, 200, arq) == NULL) break;

        strcpy(idGeo, str);

        char *ptr = strtok(idGeo, " ");

        if (!strcmp(ptr, "c")) {
            Circle circle = createCircle();

            Item item = buildCircle(str, circle);

            circleList = insertItemInFinal(circleList, item);

        } else if(!strcmp(ptr, "r")) {
            Rectangle rectangle = createRectangle();

            Item item = buildRectangle(str, rectangle);
            
            rectangleList = insertItemInFinal(rectangleList, item);
            
        } else if(!strcmp(ptr, "l")) {
            Line line = createLine();

            Item item = buildLine(str, line);

            lineList = insertItemInFinal(lineList, item);

        } else if(!strcmp(ptr, "t")) {
            Text text = createText();

            Item item = buildText(str, text);

            textList = insertItemInFinal(textList, item);
        }
    }

    fclose(arq);

    buildSVG(svgFileClean, svgFile, circleList, rectangleList , lineList, textList);

    return getSizeList(circleList, "circulos") + 
           getSizeList(rectangleList, "retangulos") +
           getSizeList(lineList, "linhas") + 
           getSizeList(textList, "textos");
}