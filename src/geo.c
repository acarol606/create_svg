#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "geo.h"
#include "circle.h"
#include "rectangle.h"
#include "line.h"
#include "text.h"


void buildGeometricForm(FILE *arq) {
    printf("--- ENTROU buildGeometricForm ---\n");
    
    List circleList = createList();
    List rectangleList = createList();
    List lineList = createList();
    List textList = createList();

    while(!feof(arq)) {
        char infos[10];
        char *eptr;
        fscanf(arq, "%s", infos);

        if (infos[0] == 'c') {
            Circle circle = createCircle();

            Item item = buildCircle(arq, circle, infos, eptr);

            circleList = insertItemInFinal(circleList, item);

        } else if(infos[0] == 'r') {
            Rectangle rectangle = createRectangle();

            Item item = buildRectangle(arq, rectangle, infos, eptr);
            
            rectangleList = insertItemInFinal(rectangleList, item);
            
        } else if(infos[0] == 'l') {
            Line line = createLine();

            Item item = buildLine(arq, line, infos, eptr);

            lineList = insertItemInFinal(lineList, item);

        } else if(infos[0] == 't') {
            Text text = createText();
            Item item = buildText(arq, text, infos, eptr);

            textList = insertItemInFinal(textList, item);
        }
        printf("--------------------------------\n");
    }

    printSizeList(circleList);
    printSizeList(rectangleList);
    printSizeList(lineList);
    printSizeList(textList);
}