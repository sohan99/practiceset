#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void * HungryWantToEat(void *);

pthread_mutex_t lock;
int chopstick = 5;
int main(){

	pthread_t	tid1,tid2,tid3,tid4,tid5;

	pthread_attr_t attr;

	pthread_attr_init(&attr);
	//while(1){
	pthread_create(&tid1,&attr,HungryWantToEat,NULL);
	pthread_create(&tid2,&attr,HungryWantToEat,NULL);
	pthread_create(&tid3,&attr,HungryWantToEat,NULL);
	pthread_create(&tid4,&attr,HungryWantToEat,NULL);
	pthread_create(&tid5,&attr,HungryWantToEat,NULL);
	//}

	

	pthread_mutex_init(&lock,NULL);

	pthread_join(tid1,NULL);

	return 0;
}
/// sample for inconsistency
void * HungryWantToEat(void *tmp){
	//while(1){
		pthread_mutex_lock(&lock);
			while(chopstick <2);
			chopstick = chopstick -2;
			sleep(3);
			printf(" %ld thread , chopstick count %d\n",(long)tmp,chopstick);
			chopstick = chopstick+2;
		pthread_mutex_unlock(&lock);
	//}
	pthread_exit(NULL);
	return NULL;
}
