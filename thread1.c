#include <stdio.h>
#include <pthread.h>

pthread_t tid[5];

void* work()
{
	printf("Hello!\n");
	
	int i;
	for (i=0;i<0xFFFFFFFF;i++);
	
	return NULL;
}

int main()
{
	int i;
	for (i=0;i<5;i++)
	{
		if( pthread_create( &tid[i], NULL, &work, NULL))
			printf("Thread creation unsuccessful\n");
		else
			printf("Thread creation successful.\n");
		
	}
	for(i=0;i<5;i++)
		pthread_join(tid[i],NULL);
		
	return 0;
}	
