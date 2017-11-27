#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int sum=0;
void *sumfunc(void *ptr)
{
	int val=(int *)ptr;
	sum=sum + (val*val);
}
int main()
{
	int n;
	scanf("%d",&n);
	pthread_t tid[n];
	int i,j,count=-1;
	for(i=0;i<=n;i++)
	{
		count++;
		void *data=(void *)i;
		int err=pthread_create(tid+count,NULL,sumfunc,data);
	}
	for(j=0;j<=n;j++)
		pthread_join(*(tid+j),NULL);

	printf("Sum = %d \n",sum);
}

