#include "svg.h"

struct anchor {
    int id;
    int isSelection;
    double x;
    double y;
};

typedef struct anchor LAnchor;
struct sel {
    double x;
    double y;
    double width;
    double height;
};

typedef struct sel LSel;

Anchor startAnchor() {
    LAnchor* a = malloc(sizeof(LAnchor*));
    a->id = NULL;
    return a;
}

int getAnchorId(Anchor anchor) {
    LAnchor* a = anchor;

    return a->id;
}

void setAnchorId(Anchor anchor, int id) {
    LAnchor* a = anchor;

    a->id = id;
}

void setAnchorX(Anchor anchor, double x) {
    LAnchor* a = anchor;

    a->x = x;
}

void setAnchorY(Anchor anchor, double y) {
    LAnchor* a = anchor;

    a->y = y;
}

void setIsSelection(Anchor anchor, int isSelection) {
    LAnchor* a = anchor;

    a->isSelection = isSelection;
}

Item createSel() {
    LSel* s = malloc(sizeof(LSel*));

    return s;
}

void setSelX(Sel s, double x) {
    LSel* sel = s;

    sel->x = x;
}

void setSelY(Sel s, double y) {
    LSel* sel = s;

    sel->y = y;
}

void setSelWidth(Sel s, double width) {
    LSel* sel = s;

    sel->width = width;
}

void setSelHeight(Sel s, double height) {
    LSel* sel = s;

    sel->height = height;
}

void buildSVG(FILE* svgFile, List clist, List rlist, List llist, List tlist, List anchorList, List selList, char* type) {


    int sizeCList = getSizeList(clist, "c");
    int sizeRList = getSizeList(rlist, "r");
    int sizeLList = getSizeList(llist, "l");
    int sizeTList = getSizeList(tlist, "t");

    printf("--- Entrou buildSVG ---\n");
    insertHeaderSVG(svgFile);

    Cell circleCell = getFirst(clist);
    Cell rectangleCell = getFirst(rlist);
    Cell lineCell = getFirst(llist);
    Cell textCell = getFirst(tlist);

    while (circleCell != NULL) {
        Item circle = getCellValue(circleCell);

        int id = getIdCircle(circle);
        char* corb = getCorBCircle(circle);
        char* corp = getCorPCircle(circle);
        double radius = getRadiusCircle(circle);
        double x = getXCircle(circle);
        double y = getYCircle(circle);


        createSVGCircle(id, corb, corp, radius, y, x, svgFile);

        circleCell = getNextCell(circleCell);
    }

    while (rectangleCell != NULL) {
        Item rectangle = getCellValue(rectangleCell);

        int id = getIdRectangle(rectangle);
        char* corb = getCorBRectangle(rectangle);
        char* corp = getCorPRectangle(rectangle);
        double x = getXRectangle(rectangle);
        double y = getYRectangle(rectangle);
        double width = getWidthRectangle(rectangle);
        double height = getHeightRectangle(rectangle);


        createSVGRectangle(id, corb, corp, width, height, y, x, svgFile);

        rectangleCell = getNextCell(rectangleCell);
    }

    int count = 0;
    while (lineCell != NULL && count < sizeLList) {
        count++;
        Item line = getCellValue(lineCell);
        

        int id = getIdLine(line);
        double initX = getInitXLine(line);
        double initY = getInitYLine(line);
        double finalX = getFinalXLine(line);
        double finalY = getFinalYLine(line);
        char* color = getColorLine(line);

        printf("count: %d - Id: %d\n\n", count, id);

        if (id > 9999 || id < 0)
        {
            break;
        }
        
        

        if (color[strlen(color) - 1] == '\n') {
            color[strlen(color) - 1] = '\0';
        }

        createSVGLine(id, initX, initY, finalX, finalY, color, svgFile);

        lineCell = getNextCell(lineCell);
    }


    while (textCell != NULL) {
        Item text = getCellValue(textCell);

        int id = getIdText(text);
        char archor = getAnchorText(text);
        double x = getXText(text);
        double y = getYText(text);
        char* value = getValueText(text);
        char* corb = getCorBText(text);
        char* corp = getCorPText(text);


        createSVGText(id, x, y, archor, corb, corp, value, svgFile);

        textCell = getNextCell(textCell);
    }

    if (strcmp(type, "q") == 0) {
        Cell anchorCell = getFirst(anchorList);
        Cell selCell = getFirst(selList);

        while (anchorCell != NULL) {
            LAnchor* anchor = (LAnchor*)getCellValue(anchorCell);

            if (anchor->isSelection == 0) {
                insertSVGAnchor(anchor->x, anchor->y, svgFile);
            }
            else {
                insertSVGAnchorSelect(anchor->x, anchor->y, svgFile);

            }

            anchorCell = getNextCell(anchorCell);
        }

        while (selCell != NULL) {
            LSel* sel = (LSel*)getCellValue(selCell);

            createSVGRectangleSel(sel->width, sel->height, sel->y, sel->x, svgFile);

            selCell = getNextCell(selCell);
        }
    }


    insertFooterSVG(svgFile);
    printf("--- Saiu buildSVG ---\n");
}

void insertHeaderSVG(FILE* svg) {
    fprintf(svg, "<svg xmlns:svg=\"http://www.w3.org/2000/svg\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">");
    fflush(svg);
}

void createSVGRectangleSel(double width, double height, double y, double x, FILE* svg) {
    fprintf(svg, "\n\t<rect style=\"fill:transparent;fill-opacity:0.5;stroke:red\" height=\"%lf\" width=\"%lf\" y=\"%lf\" x=\"%lf\" />", height, width, y, x);
    fflush(svg);
}

void createSVGRectangle(int id, char* corb, char* corp, double width, double height, double y, double x, FILE* svg) {
    fprintf(svg, "\n\t<rect id=\"%d\" style=\"fill:%s;fill-opacity:0.5;stroke:%s\" height=\"%lf\" width=\"%lf\" y=\"%lf\" x=\"%lf\" />", id, corp, corb, height, width, y, x);
    fflush(svg);
}

void createSVGCircle(int id, char* corb, char* corp, double radius, double y, double x, FILE* svg) {
    fprintf(svg, "\n\t<circle id=\"%d\" style=\"fill:%s;fill-opacity:0.5;stroke:%s\" r=\"%lf\" cy=\"%lf\" cx=\"%lf\"/>", id, corp, corb, radius, y, x);
    fflush(svg);
}

void createSVGLine(int id, double initX, double initY, double finalX, double finalY, char* color, FILE* svg) {
    fprintf(svg, "\n\t<line id=\"%d\" x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\" fill-opacity=\"50\" />", id, initX, initY, finalX, finalY, color);
    fflush(svg);
}

void createSVGText(int id, double x, double y, char archor, char* corb, char* corp, char* text, FILE* svg) {
    fprintf(svg, "\n\t<text id=\"%d\" x=\"%lf\" y=\"%lf\" text-anchor=\"%c\" stroke=\"%s\" fill=\"%s\" fill-opacity=\"50\" >\"%s\"</text>", id, x, y, archor, corb, corp, text);
    fflush(svg);
}

void insertSVGAnchor(double x, double y, FILE* svg) {
    fprintf(svg, "\n\t<circle cx=\"%lf\" cy=\"%lf\" r=\"4\" stroke-width=\"2\" fill=\"#FF0000\" />", x, y);
    fflush(svg);
}

void insertSVGAnchorSelect(double x, double y, FILE* svg) {
    fprintf(svg, "\n\t<circle stroke=\"%s\" fill=\"transparent\" r=\"4\" cy=\"%lf\" cx=\"%lf\"/>", "#FF0000", y, x);
    fflush(svg);
}

void insertFooterSVG(FILE* svg) {
    printf("--- Entrou no closeSVG ---\n\n");
    fprintf(svg, "\n</svg>");
    fflush(svg);
}

void freeAnchor(Anchor a) {
    LAnchor* anchor = a;
    free(anchor);
}

void freeSel(Sel s) {
    LSel* sel = s;
    free(sel);
}