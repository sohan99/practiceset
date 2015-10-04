#include <assert.h>

struct _time_{
	int hour;
	int min;
	int sec;
};

typedef struct _time_ Time;

Time getNewClock(); /* every thing will be initialized to zero*/
Time insertTime(unsigned int,unsigned int,unsigned int);
Time addTime(Time t1,Time t2);
/* warning : bellow 3 function is not generalized */
Time addSec(Time,int);
Time addMin(Time,int);
Time addHour(Time,int);

/* spec*/
int main(){

	Time t1 = getNewClock();
	assert(t1.sec==0);
	assert(t1.min==0);
	assert(t1.hour==0);

	t1=insertTime(2,30,5);
	Time t2=insertTime(3,50,5);
	Time t3=insertTime(23,55,59);

	t1=addTime(t1,t2);
	assert(t1.sec==10);
	assert(t1.min==20);
	assert(t1.hour==6);

	t1=addTime(t1,t3);
	assert(t1.sec==9);
	assert(t1.min==16);
	assert(t1.hour==6);


	

	return 0;
}
/* function to initialize to zero;*/
Time getNewClock(){
	return insertTime(0,0,0);
}

Time insertTime( unsigned int hour,unsigned int min,unsigned int sec){

	Time t;
	assert((sec < 60)&&(min<60)&&(hour<24)); // everytime object should follow the standard
	if(sec < 60){
		t.sec=sec;
	}
	if(min<60){
		t.min = min;
	}
	if(hour < 24){
		t.hour = hour;
	}
	return t;
}

Time addTime(Time t1,Time t2){

	/* adds time from t1 to t2;*/
	t1= addSec(t1,t2.sec);
	t1= addMin(t1,t2.min);
	t1= addHour(t1,t2.hour);

	return t1;
}

Time addSec(Time t, int seconds){
	if((t.sec+seconds)>59){
		t=addMin(t,1);
		t.sec = (t.sec+seconds)%60;
	}else {
		t.sec+=seconds;
	}

	return t;
}

Time addMin(Time t,int min){
	
	if((t.min+min) > 59){
		t=addHour(t,1);
		t.min = (t.min+min)%60;
	}else {
		t.min+=min;
	}

	return t;
}

Time addHour(Time t,int hour){

	if((t.hour + hour)>23)
		t.hour = (t.hour + hour) % 24;
	else 
		t.hour+=hour;

	return t;
}