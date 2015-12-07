// Box #4: Implicit Thread Exit

#include <pthread.h>
#include <stdio.h>

///////////////////////////////////////////////////////
void *ChildThread(void *arg)
	{
	int argument=(int)arg;
  int i;
	for(i=1;i<=argument;++i)
		{  printf(" Child Count - %d\n",i); }

	// Thread Exits Implicitly
	return 0;
	}


/////////////////////////////////////////////////////
int main(void)
	{
  pthread_t hThread;
  int x=100;
	pthread_create(&hThread,NULL,ChildThread,(void *)x);
	pthread_join(hThread,NULL);
	printf("Parent is continuing....\n"); return 0;
	}