#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void * readFile(void *);

void * writeFile(void *);

pthread_mutex_t lock;

int main(){

	pthread_t	tid1,tid2;

	pthread_attr_t attr;

	pthread_attr_init(&attr);

	pthread_create(&tid1,&attr,readFile,NULL);
	pthread_create(&tid2,&attr,writeFile,NULL);

	pthread_mutex_init(&lock,NULL);

	pthread_join(tid1,NULL);

	return 0;
}
/// sample for inconsistency
void * readFile(void *tmp){
	int i;
	pthread_mutex_lock(&lock);
	//pthread_mutex_lock(&lock); stravation
	
	printf(" hi there \n");

	pthread_mutex_unlock(&lock);

	for(i=0;i<100;i++){
		printf("ccccc");
	}
	return NULL;
}

void * writeFile(void * tmp){

	pthread_mutex_lock(&lock);
	int i;
	for(i=0;i<100;i++)
	printf("dddddd");
	pthread_mutex_unlock(&lock);
	return NULL;

}