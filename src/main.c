#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "system.h"
#include "files.h"
#include "list.h"

void main(int argc, char **argv) {

    Parameters *param = (Parameters*) createParameters(argc, argv);

    char *pathGeo = makePathGeoFile(param);

    FILE *geoFile = loadFile(pathGeo);

    buildGeometricForm(geoFile);

    if (geoFile == NULL) {
        return;
    }
}