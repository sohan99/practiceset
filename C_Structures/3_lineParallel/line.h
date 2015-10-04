
struct _line_{
	int x1;
	int y1;
	int x2;
	int y2;
};

typedef struct _line_ Line;

/* createLine (x1,y1,x2,y2)*/
Line createLine(int,int,int,int);

float getSlope(Line); 

int isParallel(Line,Line);
