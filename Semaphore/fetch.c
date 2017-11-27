#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int common=1;

void fetch_and_add(int *local,int x)
{
	*local=common;
	common+=x;
}

void *p(void *ptr)
{
	int local=0;
	int x=0;
	while(1)
	{
		printf("NCS p\n");
		sleep(1);
		do{
			fetch_and_add(&local,1);
			sleep(rand()%2);
			x++;
		}while(local!=1);
		printf("CS P \n");
		sleep(1);
		fetch_and_add(&local,-common);
		printf("p leaves CS\n");
		sleep(1);
	}
}

void *q(void *ptr)
{
	int local=0;
	int x=0;
	while(1)
	{
		printf("NCS q\n");
		sleep(1);
		do{
			fetch_and_add(&local,1);
			sleep(rand()%3);
			x++;
		}while(local!=1);
		printf("CS q\n");
		sleep(1);
		fetch_and_add(&local,-common);
		printf("Q leaves CS\n");
		sleep(1);
	}
}
int main()
{
	pthread_t tid[2];
	pthread_create(&tid[0],NULL,(void*)&p,NULL);
	pthread_create(&tid[1],NULL,(void*)&q,NULL);
	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
}