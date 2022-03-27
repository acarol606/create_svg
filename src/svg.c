#include <stdio.h>
#include <stdlib.h>
#include "svg.h"

void insertHeaderSVG() {
    FILE *svg = fopen("/home/vfsilva/estudo/repositories/project/output/teste.svg", "a");
    fprintf(svg, "<svg xmlns:svg=\"http://www.w3.org/2000/svg\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">");
    fclose(svg);
}

void createSVGRectangle(char *corb, char *corp, double width, double height, float y, float x) {
    FILE *svg = fopen("/home/vfsilva/estudo/repositories/project/output/teste.svg", "a");
    fprintf(svg, "<rect style=\"fill:%s;fill-opacity:0.5;stroke:%s\" height=\"%lf\" width=\"%lf\" y=\"%f\" x=\"%f\" />", corb, corp, width, height, y, x);
    fclose(svg);
}

void createSVGCircle(char *corb, char *corp, double radius, double y, double x) {
    printf("-- ENTROU createSVGCircle ---\n");
    FILE *svg = fopen("/home/vfsilva/estudo/repositories/project/output/teste.svg", "a");
    fprintf(svg, "<circle style=\"fill:%s;fill-opacity:0.5;stroke:%s\" r=\"%lf\" cy=\"%lf\" cx=\"%lf\"/>", corb, corp, radius, y, x);
    fclose(svg);
}

void closeSVG() {
    FILE *svg = fopen("/home/vfsilva/estudo/repositories/project/output/teste.svg", "a");
    fprintf(svg, "</svg>");
    fclose(svg);
}