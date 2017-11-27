#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>

int n=10;
int a[]={10,9,8,7,6,5,4,3,2,1};
sem_t s1,s2;

void *sort1()
{
	sleep(2);
	int i,j,temp;
	for(i=0;i<=n/2;i++)
	{
		for(j=i+1;j<=n/2;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	sem_post(&s1);
}

void *sort2()
{
	sleep(2);
	int i,j,temp;
	for(i=(n/2)+1;i<=n-1;i++)
	{
		for(j=i+1;j<=n-1;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	sem_post(&s2);
}

void *merge(void *ptr)
{
	printf("Waiting to have first half sorted\n");
	sem_wait(&s1);
	sleep(1);
	printf("Waiting to have second half sorted\n");
	sem_wait(&s2);
	sleep(1);
	int arr[n],c=0;
	int i,j;

	for(i=0,j=(n/2)+1;i<=n/2&&j<=n-1;)
	{
		if(a[i]<a[j])
			arr[c++]=a[i++];
		else
			arr[c++]=a[j++];
	}
	while(i<=n/2)
		arr[c++]=a[i++];
	while(j<=n-1)
		arr[c++]=a[j++];
	for(i=0,j=0;i<=n-1;i++,j++)
		a[i]=arr[j];
	printf("Sorted array is : ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}

int main()
{
	sem_init(&s1,0,0);
	sem_init(&s2,0,0);
	printf("Initial array : ");
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}printf("\n");
	pthread_t s1,s2,mid;
	pthread_create(&s1,NULL,(void*)&sort1,NULL);
	pthread_create(&s2,NULL,(void*)&sort2,NULL);
	pthread_create(&mid,NULL,(void*)&merge,NULL);
	pthread_join(sort1,NULL);
	pthread_join(sort2,NULL);
	pthread_join(merge,NULL);
}