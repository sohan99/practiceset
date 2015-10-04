#include "line.h"
#include<assert.h>
#include<stdio.h>

int main(){

	Line l = createLine(1,2,1,4);
	Line l2 = createLine(2,2,2,4);
	Line l3 = createLine(2,3,3,4);
	
	assert(isParallel(l,l2));
	assert(!isParallel(l,l3));


	printf(" %f %f ",getSlope(l),getSlope(l3));
	/*l = createLine(4,4,4,4);// this will abort */

	return 0;
}

Line createLine(int x1,int y1,int x2,int y2){

	assert(!(x1==x2 && y1==y2)); //since this is not a line 
	Line l={x1,y1,x2,y2};
	return l;

}


float getSlope(Line l){
	return (((float)(l.x2-l.x1))>0)? (l.y2-l.y1)/(float)(l.x2-l.x1) : 0 ;
}

int isParallel(Line x,Line y){
	return (getSlope(x)==getSlope(y));
}