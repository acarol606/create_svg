#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "system.h"
#include "files.h"
#include "list.h"
#include "qry.h"

void main(int argc, char **argv) {

    Parameters param = createParameters(argc, argv);

    char *pathGeo = makePathGeoFile(param);

    FILE *geoFile = loadFile(pathGeo);
    
    if(geoFile == NULL) {
        printf("Problemas na abertura do arquivo!\n");
        return;
    }

    char *outputDir = getOutputDir(param);

    int sizePolygon = buildGeometricForm(geoFile, outputDir);


    char *pathQry = makePathQryFile(param);

    FILE *qryFile = loadFile(pathQry);

    queryCommands(qryFile, sizePolygon);

    if (geoFile == NULL) {
        return;
    }
}