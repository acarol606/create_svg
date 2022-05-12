#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "system.h"
#include "files.h"
#include "list.h"
#include "qry.h"
#include "geo.h"

int main(int argc, char **argv) {

    List circleList = createList();
    List rectangleList = createList();
    List lineList = createList();
    List textList = createList();
    List anchorList = createList();
    List selList = createList();
    
    Parameters param = createParameters(argc, argv);
    
    FILE *geoFile = loadFile(getGeoPath(param));
    
    if(geoFile == NULL) {
        printf("Problemas na abertura do arquivo!\n");
        return 0;
    }

    char *outputDir2 = getOutputDir(param, 's');
    
    FILE *svgFileClean = fopen(outputDir2, "w");

    if(svgFileClean == NULL) {
        printf("Arquivo svg sem qry nulo!\n\n");
        return 0;
    }
    
    int sizePolygon = buildGeometricForm(geoFile, circleList, rectangleList, lineList, textList);
    buildSVG(svgFileClean, circleList, rectangleList , lineList, textList, anchorList, selList, "c");
    fclose(svgFileClean);

    FILE *qryFile = loadFile(getQryPath(param));

    if(qryFile == NULL) {
        printf("Arquivo qry nulo!\n\n");
        return 0;
    }

    FILE *txtFile = fopen(getTxtPath(param), "w");

    if(txtFile == NULL) {
        printf("Arquivo txt nulo!\n\n");
        return 0;
    }
    
    char *outputDir = getOutputDir(param, 'q');

    FILE *svgFile = fopen(outputDir, "w");

    if(svgFile == NULL) {
        printf("Arquivo svg com qry nulo!\n\n");
        return 0;
    }

    if (getSizeList(circleList, "circulos") == 0) {
        freeList(circleList);  
        circleList = 0; 
    }
    
    if (getSizeList(rectangleList, "retangulos") == 0) {
        freeList(rectangleList);
        rectangleList = 0;
    }
    
    if (getSizeList(textList, "textos") == 0) {
        freeList(textList);
        textList = 0;
    }

    queryCommands(selList, anchorList, txtFile, qryFile, sizePolygon, circleList, rectangleList, lineList, textList);
    getSizeList(lineList, "linhas");
    buildSVG(svgFile, circleList, rectangleList , lineList, textList, anchorList, selList, "q");

    fclose(svgFile);
    fclose(txtFile);
}