#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "system.h"
#include "files.h"
#include "list.h"

void main(int argc, char **argv) {

    Parameters *param = (Parameters*) createParameters(argc, argv);

    List *list = createList();

    char *pathGeo = makePathGeoFile(param);

    FILE *geoFile = loadFile(pathGeo);

    while(!feof(geoFile)) {
        Item *item = buildGeometricForm(geoFile);
        printf("Foi 1\n");
    }

    if (geoFile == NULL) {
        return;
    }
}