#include<stdio.h>
#include<pthread.h>
static int turn = 1;
void * p(){
	while(1){
	sleep(2);
		while(turn!=1)
			printf("Thread 1 waiting...\n");
		if(turn==1){
			sleep(2);
			printf("Thread 1 in critical section.\n");
		}
		turn = 2;
	}
}

void * q(){
	while(1){
	sleep(2);
		while(turn!=2)
			printf("Thread 2 waiting...\n");
		if(turn==2){
			sleep(2);
			printf("Thread 2 in critical section.\n");
		}
		turn = 1;
	}
}
int main(){
	pthread_t tid1, tid2;
	

	pthread_create(&tid1, NULL, p, NULL);
	pthread_create(&tid2, NULL, q, NULL);

	pthread_exit(NULL);
	return 0;
}
