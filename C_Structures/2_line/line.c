#include "line.h"
#include<assert.h>

int main(){

	Line l = createLine(1,2,1,4);
	assert(checkLine(l)==1);

	l = createLine(2,4,1,4);
	assert(checkLine(l)==2);

	l = createLine(2,3,1,4);
	assert(checkLine(l)==3);

	/*l = createLine(4,4,4,4);// this will abort */

	return 0;
}

Line createLine(int x1,int y1,int x2,int y2){

	assert(!(x1==x2 && y1==y2)); //since this is not a line 
	Line l={x1,y1,x2,y2};
	return l;

}

int checkLine(Line l){

	if (l.x1==l.x2) return 1;
	if (l.y1==l.y2) return 2;
	return 3;

}