#include "qry.h"

void inp(FILE *qryFile, char *command, Queue queue) {
    printf("--- INICIO INP ---\n");
    int id;

    fscanf(qryFile, "%s", command);
    printf("%s\n", command);
    id = atoi(command);

    insertQueue(queue, id);

    // printf("%d\n", id);
}

void queryCommands(FILE *qryFile, int capacity) {
    Queue queue = createQueue(capacity);

    while(!feof(qryFile)) {
        char *command;
        char *eptr;
        fscanf(qryFile, "%s", command);
        printf("Command: %s\n\n", command);
        if(strcmp(command, "inp")==0) {
            inp(qryFile, command, queue);
        }
    }

}