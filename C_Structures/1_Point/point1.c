#include "point.h"
#include <assert.h>

/*Spec  */
int main(){

	Point p = createPoint(2,16);
	assert(getQuadrent(p)==1);

	Point q = createPoint(2,16);
	assert(comaparePoint(p,q));

	p = createPoint(-1,16);
	q= createPoint(3,-167);
	assert(!comaparePoint(p,q));
	assert(getQuadrent(p)==2);
	assert(getQuadrent(q)==4);
	p = createPoint(-2,-16);
	assert(getQuadrent(p)==3);
	p = createPoint(0,0);
	assert(getQuadrent(p)==1);

	return 0;
}

/* implementation*/

Point createPoint(int x,int y){
	Point p={x,y};
	return p;
}

int getQuadrent(Point p){

		if(p.x >=0){
			if(p.y>=0) return 1; 	/* xand y >=0 */
			return 4; 	/* x >0 and y<0 */
		}
		if(p.y>=0)
			return 2; /* x<0 and y>=0 */
		return 3;	/*  x<0 and y<0 */
	
}
int comaparePoint(Point p,Point q){

	return (p.x==q.x && p.y==q.y);

}
