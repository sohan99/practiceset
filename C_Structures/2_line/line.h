
struct _line_{
	int x1;
	int y1;
	int x2;
	int y2;
};

typedef struct _line_ Line;

/* createLine (x1,y1,x2,y2)*/
Line createLine(int,int,int,int);

/* returns 1 if vertical 2 if horizontal 3 if oblique*/
int checkLine(Line);
