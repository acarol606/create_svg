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
    
    FILE *geoFile = loadFile(pathGeo);
    
    if(geoFile == NULL) {
        printf("Problemas na abertura do arquivo!\n");
        return 0;
    }

    char *teste = getQryName(param);

    char *outputDir = getOutputDir(param, ".svg");
    char *outputDir2 = getOutputDir2(param, ".svg");

    FILE *svgFile = fopen(outputDir, "w");
    FILE *svgFileClean = fopen(outputDir2, "w");

    if(svgFile == NULL) {
        printf("Arquivo nulo!\n\n");
        return 0;
    }
    
    int sizePolygon = buildGeometricForm(svgFileClean, geoFile, outputDir, circleList, rectangleList, lineList, textList, svgFile);

    char *pathQry = makePathQryFile(param);

    FILE *qryFile = loadFile(pathQry);

    if(qryFile == NULL) {
        printf("Arquivo nulo!\n\n");
        return 0;
    }

    char *outputDirTxt = getOutputDir(param, ".txt");

    FILE *txtFile = fopen(outputDirTxt, "w");

    if(txtFile == NULL) {
        printf("Arquivo nulo!\n\n");
        return 0;
    }

    queryCommands(txtFile, qryFile, sizePolygon, circleList, rectangleList, lineList, textList, svgFile);

    insertFooterSVG(svgFile);
    insertFooterSVG(svgFileClean);

    fclose(svgFile);
    fclose(svgFileClean);
    fclose(txtFile);
}