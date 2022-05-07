#include "svg.h"

void buildSVG(FILE *svgFileClean, FILE *svgFile, List clist, List rlist ,List llist , List tlist) {
    insertHeaderSVG(svgFile);
    insertHeaderSVG(svgFileClean);

    Cell circleCell = getFirst(clist);
    Cell rectangleCell = getFirst(rlist);
    Cell lineCell = getFirst(llist);
    Cell textCell = getFirst(tlist);
    
    while(circleCell != NULL) {
        Item circle = getCellValue(circleCell);

        int id = getIdCircle(circle);
        char *corb = getCorBCircle(circle);
        char *corp = getCorPCircle(circle);
        double radius = getRadiusCircle(circle);
        double x = getXCircle(circle);
        double y = getYCircle(circle);


        createSVGCircle(id, corb, corp, radius, y, x, svgFile);
        createSVGCircle(id, corb, corp, radius, y, x, svgFileClean);

        circleCell = getNextCell(circleCell);
    }
    
    while(rectangleCell != NULL) {
        Item rectangle = getCellValue(rectangleCell);

        int id = getIdRectangle(rectangle);
        char *corb = getCorBRectangle(rectangle);
        char *corp = getCorPRectangle(rectangle);
        double x = getXRectangle(rectangle);
        double y = getYRectangle(rectangle);
        double width = getWidthRectangle(rectangle);
        double height = getHeightRectangle(rectangle);


        createSVGRectangle(id, corb, corp, width, height, y, x, svgFile);
        createSVGRectangle(id, corb, corp, width, height, y, x, svgFileClean);

        rectangleCell = getNextCell(rectangleCell);
    }
    
    while(lineCell != NULL) {
        Item line = getCellValue(lineCell);

        int id = getIdLine(line);
        double initX = getInitXLine(line);
        double initY = getInitYLine(line);
        double finalX = getFinalXLine(line);
        double finalY = getFinalYLine(line);
        char *color = getColorLine(line);

        if (color[strlen(color)-1] == '\n') {
            color[strlen(color)-1] = '\0';
        }
        
        createSVGLine(id, initX, initY, finalX, finalY, color, svgFile);
        createSVGLine(id, initX, initY, finalX, finalY, color, svgFileClean);

        lineCell = getNextCell(lineCell);
    }

    
    while(textCell != NULL) {
        Item text = getCellValue(textCell);

        int id = getIdText(text); 
        char archor = getAnchorText(text);
        double x = getXText(text);
        double y = getYText(text);
        char *value = getValueText(text);
        char *corb = getCorBText(text);
        char *corp = getCorPText(text);


        createSVGText(id, x, y, archor, corb, corp, value, svgFile);
        createSVGText(id, x, y, archor, corb, corp, value, svgFileClean);

        textCell = getNextCell(textCell);
    }
}

void insertHeaderSVG(FILE *svg) {
    fprintf(svg, "<svg xmlns:svg=\"http://www.w3.org/2000/svg\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">");
    fflush(svg);
}

void createSVGRectangle(int id, char *corb, char *corp, double width, double height, double y, double x, FILE *svg) {
    fprintf(svg, "\n\t<rect id=\"%d\" style=\"fill:%s;fill-opacity:0.5;stroke:%s\" height=\"%lf\" width=\"%lf\" y=\"%lf\" x=\"%lf\" />", id, corp, corb, height, width, y, x);
    fflush(svg);
}

void createSVGCircle(int id, char *corb, char *corp, double radius, double y, double x, FILE *svg) {
    fprintf(svg, "\n\t<circle id=\"%d\" style=\"fill:%s;fill-opacity:0.5;stroke:%s\" r=\"%lf\" cy=\"%lf\" cx=\"%lf\"/>", id, corp, corb, radius, y, x);
    fflush(svg);
}

void createSVGLine(int id, double initX, double initY, double finalX, double finalY, char *color, FILE *svg) {
    fprintf(svg, "\n\t<line id=\"%d\" x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\" fill-opacity=\"50\" />", id, initX, initY, finalX, finalY, color);
    fflush(svg);
}

void createSVGText(int id, double x, double y, char archor, char *corb, char *corp, char *text, FILE *svg) {
    fprintf(svg, "\n\t<text id=\"%d\" x=\"%lf\" y=\"%lf\" text-anchor=\"%c\" stroke=\"%s\" fill=\"%s\" fill-opacity=\"50\" >\"%s\"</text>", id, x, y, archor, corb, corp, text);
    fflush(svg);
}

void insertSVGAnchor(double x, double y, FILE *svg) {
    printf("Anchor\n\n");
    fprintf(svg, "\n\t<circle cx=\"%lf\" cy=\"%lf\" r=\"4\" stroke-width=\"2\" fill=\"red\" />", x, y);
    fflush(svg);
}

void insertSVGAnchorSelect(double x, double y, FILE *svg) {
    fprintf(svg, "\n\t<circle stroke=\"%s\" fill=\"transparent\" r=\"4\" cy=\"%lf\" cx=\"%lf\"/>", "#FF0000", y, x);
    fflush(svg);
}

void insertFooterSVG(FILE *svg) {
    printf("--- Entrou no closeSVG ---\n\n");
    fprintf(svg, "\n</svg>");
    fflush(svg);
}