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
    
    FILE *geoFile = loadFile(getGeoPath(param));
    
    if(geoFile == NULL) {
        printf("Problemas na abertura do arquivo!\n");
        return 0;
    }

    char *outputDir = getOutputDir(param, 'q');
    char *outputDir2 = getOutputDir(param, 's');

    FILE *svgFile = fopen(outputDir, "w");

    if(svgFile == NULL) {
        printf("Arquivo svg com qry nulo!\n\n");
        return 0;
    }

    FILE *svgFileClean = fopen(outputDir2, "w");

    if(svgFileClean == NULL) {
        printf("Arquivo svg sem qry nulo!\n\n");
        return 0;
    }
    
    int sizePolygon = buildGeometricForm(svgFileClean, geoFile, outputDir, circleList, rectangleList, lineList, textList, svgFile);

    insertFooterSVG(svgFileClean);
    fclose(svgFileClean);

    FILE *qryFile = loadFile(getQryPath(param));

    printf("Qry path: %s\n\n", getQryPath(param));

    if(qryFile == NULL) {
        printf("Arquivo qry nulo!\n\n");
        return 0;
    }

    FILE *txtFile = fopen(getTxtPath(param), "w");

    if(txtFile == NULL) {
        printf("Arquivo txt nulo!\n\n");
        return 0;
    }

    queryCommands(txtFile, qryFile, sizePolygon, circleList, rectangleList, lineList, textList, svgFile);

    insertFooterSVG(svgFile);

    fclose(svgFile);
    fclose(txtFile);
}