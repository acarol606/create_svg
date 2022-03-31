#include "svg.h"

void insertHeaderSVG(FILE *svg) {
    printf("--- Entrou no insertHeaderSVG ---\n\n");
    fprintf(svg, "<svg xmlns:svg=\"http://www.w3.org/2000/svg\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">");
}

void createSVGRectangle(char *corb, char *corp, double width, double height, float y, float x, FILE *svg) {
    printf("--- Entrou no createSVGRectangle ---\n\n");
    fprintf(svg, "\n<rect style=\"fill:%s;fill-opacity:0.5;stroke:%s\" height=\"%lf\" width=\"%lf\" y=\"%f\" x=\"%f\" />", corb, corp, width, height, y, x);
}

void createSVGCircle(char *corb, char *corp, double radius, double y, double x, FILE *svg) {
    printf("-- Entrou no createSVGCircle ---\n\n");
    fprintf(svg, "\n<circle style=\"fill:%s;fill-opacity:0.5;stroke:%s\" r=\"%lf\" cy=\"%lf\" cx=\"%lf\"/>", corb, corp, radius, y, x);
}

void insertFooterSVG(FILE *svg) {
    printf("--- Entrou no closeSVG ---\n\n");
    fprintf(svg, "\n</svg>");
}