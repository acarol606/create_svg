#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "system.h"
#include "files.h"

void main(int argc, char **argv) {

    Parameters *param = createParameters();

    param = setParameters(argc, argv, param);

    char *pathGeo = buildFilePath(param->inputDir, param->nameGeoFile);

    FILE *geoFile = loadFile(pathGeo);

    if (geoFile == NULL) {
        return;
    }

    buildGeometricForm(geoFile);

}