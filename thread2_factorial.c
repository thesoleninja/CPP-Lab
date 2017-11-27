#include <stdio.h>
#include <pthread.h>

pthread_t tid;
int *ret;
int y ;
void* factorial(void * num)
{
	int n = *(int *)num;
	if(n==0)
	{
		y=1;
		ret=&y;
		pthread_exit(&ret);
	}
		
	pthread_t id;
	
	int x = n-1;
	
	if( pthread_create( &id, NULL, &factorial, (void *)&x))
			printf("Thread creation unsuccessful\n");
	else
			printf("Thread creation successful.\n");
			
	pthread_join( id, (void **)&ret);			
	*ret *= n;
	pthread_exit(&ret);
	
	return NULL;
}

int main( int argc, char** argv )
{
	int n = atoi(argv[1]), i; 
	
	if( pthread_create( &tid, NULL, &factorial, (void *)&n))
			printf("Thread creation unsuccessful\n");
	else
			printf("Thread creation successful.\n");
	pthread_join(tid, (void**)&ret);
	printf("Factorial : 	%d\n", *ret);
	return 0;
}	
