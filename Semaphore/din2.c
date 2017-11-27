#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<signal.h>
#include<semaphore.h>
sem_t s[5] ;
sem_t room;
pthread_t t[5];

void *p(int p)
{
	int n=p;
	while(1)
	{
		printf("Philosopher %d : thinking\n",n+1);
		sleep(1);
		sem_wait(&room);
		printf("Philosopher %d : entered the room\n",n+1);
		sleep(1);
		printf("Philosopher %d : waiting for left fork\n",n+1);
		sem_wait(&s[n]);
		printf("Philosopher %d got left fork\n",n+1);
		sleep(1);
		printf("Philosopher %d : waiting for right fork\n",n+1);
		sem_wait(&s[(n+1)%5]);
		printf("Philosopher %d got right fork\n",n+1);
		sleep(1);
		printf("Philosopher %d : eating\n",n+1);
		sleep(1);
		printf("Philosopher %d has put left fork down.\n",n+1);
		sleep(1);
		sem_post(&s[n]);
		printf("Philosopher %d has put right fork down.\n",n+1);
		sleep(1);
		sem_post(&s[(n+1)%5]);
		printf("Philosopher %d left the room\n",n+1);
		sleep(1);
		sem_post(&room);
	}
}
void main(){
    int i;
    for(i=0;i<5;i++)
        sem_init(&s[i], 0, 1);
    sem_init(&room, 0, 4);

    for(i=0;i<5;i++)
    {
        pthread_create(&t[i], NULL, (void*)&p, (void*)i);
		sleep(1);
    }
    pthread_exit(NULL);
}

