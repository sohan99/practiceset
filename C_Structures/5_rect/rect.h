#include "point.h"
struct _rect_{
	Point a;
	Point b;
	Point c;
	Point d;
};

typedef struct _rect_ Rect;


Rect createRectangle(int,int,int,int,int,int,int,int);

float calcDistance(Point,Point);

float calcArea(Rect);

float calcPerimiter(Rect);

int compareArea(Rect,Rect);

