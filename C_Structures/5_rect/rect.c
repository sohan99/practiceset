/*
* assumpption that user will enter only rectangle values from point a,b,c,d in sequence;
*/
#include "rect.h"
#include <assert.h>
#include <math.h>

#define SQUARE(X) X*X

int main(){

	Rect r = createRectangle(1,2,1,4,8,4,8,2);
	Rect r2 = createRectangle(1,3,1,3,8,4,8,2);
	assert(r.a.x==1);
	assert((int)calcDistance(r.a,r.b)==2);
	assert((int)calcDistance(r.b,r.c)==7);
	assert(calcArea(r)==(2*7.0));
	assert(calcPerimiter(r)==2.0*(2+7.0));
	assert(!compareArea(r,r2));

	return 0;
}


Point createPoint(int x,int y){
	Point p={x,y};
	return p;
}

Rect createRectangle(int x1,int y1,int x2,int y2,int x3,int y3 ,int x4 ,int y4){

	Rect r;
	r.a = createPoint(x1,y1);
	r.b = createPoint(x2,y2);
	r.c = createPoint(x3,y3);
	r.d = createPoint(x4,y4);

	return r;
}

float calcDistance(Point a,Point b){
	return sqrt(SQUARE((a.x-b.x)) + SQUARE((a.y-b.y)));
}

float calcArea(Rect r){
	return calcDistance(r.a,r.b)*calcDistance(r.b,r.c);
}

float calcPerimiter(Rect r){
	return 2.0*(calcDistance(r.a,r.b)+calcDistance(r.b,r.c));
}

int compareArea(Rect r1 ,Rect r2){
	return (calcArea(r1)==calcArea(r2));
}
