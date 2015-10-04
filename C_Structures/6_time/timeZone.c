#include <assert.h>

struct _time_{
	int hour;
	int min;
	int sec;
};

struct _time_12{
	int hour;
	int min;
	int sec;
	char amPm;
};

typedef struct _time_ Time;
typedef struct _time_12 Time12;

Time getNewClock(); /* every thing will be initialized to zero*/
Time insertTime(unsigned int,unsigned int,unsigned int);
Time addTime(Time t1,Time t2);
/* warning : bellow 3 function is not generalized */
Time addSec(Time,int);
Time addMin(Time,int);
Time addHour(Time,int);

Time12 getTimeIn12hrs(Time);
Time getTimeIn24hrs(Time12 t12);

/* spec*/
int main(){

	Time t1 = getNewClock();
	assert(t1.sec==0);
	assert(t1.min==0);
	assert(t1.hour==0);

	t1=insertTime(2,30,5);
	Time t2=insertTime(3,50,5);
	Time t3=insertTime(23,55,59);

	Time12 t4 = getTimeIn12hrs(t3);
	assert(t4.sec==59);
	assert(t4.min==55);
	assert(t4.hour==11);
	assert(t4.amPm=='p');

	Time t6 = getNewClock();
	t6=getTimeIn24hrs(t4);
	assert(t6.sec==59);
	assert(t6.min==55);
	assert(t6.hour==23);

	Time12 t5 = getTimeIn12hrs(t1);
	assert(t5.sec==5);
	assert(t5.min==30);
	assert(t5.hour==2);
	assert(t5.amPm=='a');

	t1 = getTimeIn24hrs(t5);
	assert(t1.sec==5);
	assert(t1.min==30);
	assert(t1.hour==2);

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
	assert((sec < 60) && (min < 60) && (hour < 24)); // everytime object should follow the standard
	if(sec < 60){
		t.sec = sec;
	}
	if(min < 60){
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

	int secondSum = t.sec + seconds;
	while(secondSum > 59){
			t = addMin(t,1);
			secondSum -= 60;
	}
	t.sec = secondSum;

	return t;
}

Time addMin(Time t,int min){

	int minuteSum = t.min + min;
	while(minuteSum > 59){
			t = addHour(t,1);
			minuteSum -= 60;
	}
	t.min = minuteSum;

	return t;
}

Time addHour(Time t,int hour){

	t.hour = ((t.hour + hour)>23)? (t.hour + hour) % 24 : t.hour + hour;
	return t;
}

Time12 getTimeIn12hrs(Time t24){
	Time12 t12;

	if(t24.hour > 11)
		t12.amPm = 'p';
	else 
		t12.amPm = 'a';

	t12.min = t24.min;
	t12.sec = t24.sec;
	t12.hour= t24.hour % 12;

	return t12;
}

Time getTimeIn24hrs(Time12 t12){
	Time t24;

	t24.min = t12.min;
	t24.sec = t12.sec;
	t24.hour = ('p' == t12.amPm)? 12 + t12.hour : t12.hour;

	return t24;
}