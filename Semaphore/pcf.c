#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>
#define N 10
sem_t notEmpty, notFull;
int count=0;
int valp;
int q[N], front =-1, rear=-1;

void push(int n){
    if(front==-1 && rear==-1)
	{
		q[++rear]=n;
		front=1;
	}
	else
		q[++rear]=n;
};
int pop(){
	if(rear==0)
	{
	     rear--;
	     return front--;
	}
	else
		rear--;
};

void * producer(void * k){
    int *j = (int *)k;
    int i = *j;
    while(1){
        printf("Starting Production: %d\n", ++count % N );
        sem_wait(&notFull);
        //push(i);
        printf("Production done: %d\n", count % N );
        sem_post(&notEmpty);
    }
}
void * consumer(){
    while(1){
        sem_wait(&notEmpty);
        //int d=pop();
        sem_getvalue(&notFull,&valp);
        printf("Product Consumed :%d\n",N - valp+1);
        //printf("Product Consumed \n");
        sem_post(&notFull);

    }
}
void main(){
    int i;
    sem_init(&notEmpty, 0, 0);
    sem_init(&notFull, 0, N);

    pthread_t tid1,tid2;
        pthread_create(&tid1, NULL, producer, &i);
        pthread_create(&tid2, NULL, consumer, NULL);
    pthread_exit(NULL);
}