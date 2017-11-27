#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<signal.h>
#include<semaphore.h>
sem_t s[5] ;
pthread_t t[5];

void * p(void * k){
    int *j = (int *)k;
    int i = *j;
    while(1){

        printf("Philosopher %d : thinking\n",i+1);
        sleep(1);
        printf("Philosopher %d : waiting for left fork\n",i+1);
        sem_wait(&s[i]);
        printf("Philosopher %d got left fork\n",i+1);
        printf("Philosopher %d : waiting for right fork\n",i+1);
        sem_wait(&s[(i+1)]);
        printf("Philosopher %d got right fork\n",i+1);
        printf("Philosopher %d : eating\n",i+1);
        sleep(1);
        printf("Philosopher %d has put left fork down.\n",i+1);
        sleep(1);
        sem_post(&s[i]);
        sleep(1);
        printf("Philosopher %d has put right fork down.\n",i+1);
        sem_post(&s[(i+1)]);

    }
}
void * q(){
    while(1){
        printf("Philosopher %d : thinking\n",5);
        sleep(1);
        printf("Philosopher %d : waiting for left fork\n",5);
        sem_wait(&s[0]);
        printf("Philosopher %d got left fork\n",5);
        printf("Philosopher %d : waiting for right fork\n",5);
        sem_wait(&s[4]);
        printf("Philosopher %d got right fork\n",5);
        printf("Philosopher %d : eating\n",5);
        sleep(1);
        printf("Philosopher %d has put left fork down.\n",5);
        sleep(1);
        sem_post(&s[0]);
        sleep(1);
        printf("Philosopher %d has put right fork down.\n",5);
        sem_post(&s[4]);

    }
}

int main()
{
	int i;
	for(i=0;i<5;i++)
		sem_init(&s[i],0,1);
	pthread_t tid[5];
	for(i=0;i<4;i++)
	{
		pthread_create(&tid[i],NULL,(void*)&p,&i);
		sleep(1);
	}

	pthread_create(&tid[i],NULL,(void*)&q,&i);
	for(i=0;i<5;i++)
		pthread_join(tid[i],NULL);
}