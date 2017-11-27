#include<stdio.h>
#include<pthread.h>
#define false 0
#define true 1		
static int	 wantp = false, wantq = false;
void * p(){
	while(1){
		sleep(2);									//non critical section
		while( wantq != false)
		{
			sleep(2);
			printf("Thread 1 waiting...\n");
		}
		wantp = true;
		sleep(2);
		printf("Thread 1 in critical section.\n");	//critical section
		sleep(2);
		wantp = false;
	}
}

void * q(){
	while(1){
		sleep(2);									//non critical section
		while( wantp != false)
		{
			sleep(2);
			printf("Thread 2 waiting...\n");
		}
		wantq = true;
		sleep(2);
		printf("Thread 2 in critical section.\n");	//critical section
		sleep(2);
		wantq = false;
	}
}
int main(){
	pthread_t tid1, tid2;
	

	pthread_create(&tid1, NULL, p, NULL);
	pthread_create(&tid2, NULL, q, NULL);

	pthread_exit(NULL);
	return 0;
}
