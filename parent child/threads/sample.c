//test approach using posix threads
// library to hold the thread
#include <pthread.h>
#include <stdio.h>
#include<unistd.h>

void* func1(void *);
struct _holeder_{

	int value;
};
typedef struct _holeder_ Holder;

int main(){
	// declare  thread id
	pthread_t thread1;

	// variable to storte thread attribute
	pthread_attr_t thread_attr;

	// initialize thread .. not yet created
	Holder h;
	h.value = 10;
	pthread_attr_init(&thread_attr);

	// create and start execution
	pid_t p = fork();
	pthread_create(&thread1,&thread_attr,func1,&h);

	// once done join  thread
	pthread_join(thread1,NULL);

	return 0;
}


void * func1(void *tmp){

	Holder *a = tmp;
	printf("Inside thread 1 \n");
	printf("%d",a->value++);
	return NULL;
}
