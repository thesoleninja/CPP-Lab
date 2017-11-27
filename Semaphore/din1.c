#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>

sem_t s[5];

void *p(int p)
{
	int n=p;
	while(1)
	{
		sleep(1);
		printf("Philosopher %d : thinking\n",n);
        printf("Philosopher %d : waiting for left fork\n",n);
		sem_wait(&s[n]);
		printf("Philosopher %d got left fork\n",n);
        printf("Philosopher %d : waiting for right fork\n",n);
		sem_wait(&s[(n+1)%5]);
		printf("Philosopher %d got right fork\n",n);
        printf("Philosopher %d : eating\n",n);
		sleep(1);
		printf("Philosopher %d has put left fork down.\n",n);
		sleep(1);
		sem_post(&s[n]);
		printf("Philosopher %d has put right fork down.\n",n);
		sleep(1);
		sem_post(&s[(n+1)%5]);
	}
}

int main()
{
	int i;
	for(i=0;i<5;i++)
		sem_init(&s[i],0,1);
	pthread_t tid[5];
	for(i=0;i<5;i++)
		pthread_create(&tid[i],NULL,(void*)&p,(void*)i);
	for(i=0;i<5;i++)
		pthread_join(tid[i],NULL);
}
