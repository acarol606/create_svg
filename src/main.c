#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "system.h"
#include "files.h"
#include "list.h"
#include "qry.h"

void main(int argc, char **argv) {

    List circleList = createList();
    List rectangleList = createList();
    List lineList = createList();
    List textList = createList();

    Parameters param = createParameters(argc, argv);

    char *pathGeo = makePathGeoFile(param);

    FILE *geoFile = loadFile(pathGeo);
    
    if(geoFile == NULL) {
        printf("Problemas na abertura do arquivo!\n");
        return;
    }

    char *outputDir = getOutputDir(param);

    FILE *svgFile = fopen(outputDir, "w");

    int sizePolygon = buildGeometricForm(geoFile, outputDir, circleList, rectangleList, lineList, textList, svgFile);

    char *pathQry = makePathQryFile(param);

    FILE *qryFile = loadFile(pathQry);

    queryCommands(qryFile, sizePolygon, circleList, rectangleList, lineList, textList, svgFile);
}