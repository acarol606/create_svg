#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "system.h"
#include "files.h"
#include "list.h"
#include "qry.h"

int main(int argc, char **argv) {

    List circleList = createList();
    List rectangleList = createList();
    List lineList = createList();
    List textList = createList();
    
    Parameters param = createParameters(argc, argv);
    
    char *pathGeo = makePathGeoFile(param);
    printf("\n\npath: %s\n\n", pathGeo);
    FILE *geoFile = loadFile(pathGeo);
    
    if(geoFile == NULL) {
        printf("1Problemas na abertura do arquivo!\n");
        return 0;
    }

    char *teste = getQryName(param);

    char *outputDir = getOutputDir(param);

    printf("Qry name main: %s\n\n", outputDir);

    FILE *svgFile = fopen(outputDir, "w");

    if(svgFile == NULL) {
        printf("Arquivo nulo!\n\n");
        return 0;
    }
    
    int sizePolygon = buildGeometricForm(geoFile, outputDir, circleList, rectangleList, lineList, textList, svgFile);

    char *pathQry = makePathQryFile(param);

    printf("Path file: %s\n\n", pathQry);

    FILE *qryFile = loadFile(pathQry);

    if(qryFile == NULL) {
        printf("Arquivo nulo!\n\n");
        return 0;
    }

    queryCommands(qryFile, sizePolygon, circleList, rectangleList, lineList, textList, svgFile);

    insertFooterSVG(svgFile);
}