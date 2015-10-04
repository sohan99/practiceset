/*
Program is beautiful if its simple

## program to find the quadrent of the point  and check the Point two point is equal;

*/


struct _point_{
	int x;
	int y;
};

typedef struct _point_ Point; 

Point createPoint(int,int);
int getQuadrent(Point);
int comaparePoint(Point,Point);