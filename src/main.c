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
    int i;
    int len = strlen(outputDirTxt);
    
    for(i=1; i<=8; i++) {
        outputDirTxt[len-i] = '\0';
    }

    strcat(outputDirTxt, ".txt");
    printf("Text: %s\n\n", outputDirTxt);

    FILE *txtFile = fopen(outputDirTxt, "w");

    if(txtFile == NULL) {
        printf("Arquivo nulo!\n\n");
        return 0;
    }

    FILE *readSVG = fopen(outputDir, "r");

    if(txtFile == NULL) {
        printf("Arquivo nulo!\n\n");
        return 0;
    }

    len = strlen(outputDir);

    char *outputDirNewSVG = (char*) malloc(sizeof(char) * strlen(outputDir));
    strcpy(outputDirNewSVG, outputDir);

    for(i=1; i<=8; i++) {
        outputDirNewSVG[len-i] = '\0';
    }

    strcat(outputDirNewSVG, ".svg");
    FILE *newSVG = fopen(outputDirNewSVG, "w");

    if(newSVG == NULL) {
        printf("Arquivo nulo!\n\n");
        return 0;
    }

    queryCommands(newSVG, readSVG, txtFile, qryFile, sizePolygon, circleList, rectangleList, lineList, textList, svgFile);

    insertFooterSVG(svgFile);
    insertFooterSVG(svgFileClean);
    insertFooterSVG(newSVG);

    fclose(newSVG);
    fclose(svgFile);
    fclose(readSVG);
    fclose(txtFile);
    fclose(svgFileClean);
    remove(outputDir);
}