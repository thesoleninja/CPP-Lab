#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define r 3
#define k 2
#define c 3
int mat1[r][k];
int mat2[k][c];
int res[r][c];
struct data{
	int row;
	int col;
};

void *multiply(void  *para)
{
	struct data *data1=(struct data*)para;
	int n,sum=0;
	for(n=0;n<k;n++){
		 sum=sum+(mat1[data1->row][n]*mat2[n][data1->col]);
		 int val=pthread_self();
	}
	res[data1->row][data1->col]=sum;

}
int main()
{
	int count=-1;
	pthread_t tid[10];
	int i,j;

	for(i=0;i<r;i++)
		for(j=0;j<k;j++)
			  scanf("%d",&mat1[i][j]);
	


	for(i=0;i<k;i++)
		for(j=0;j<c;j++)
	  		scanf("%d",&mat2[i][j]);

	for(i=0;i<r;i++)
	{
	 for(j=0;j<c;j++)
	 {  
		 count++;

	   struct data *data1 = (struct data*)malloc(sizeof(struct data));
	   
	  	data1->row=i;
	 	data1->col=j;

	  	int val=pthread_create((tid+count),NULL,multiply,data1);	

	 }
	}
	int l;
	for(l=0;l<r*c;l++)
		pthread_join(*(tid+l),NULL);

	printf("\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
	  		printf(" %d ",res[i][j]);
	  		
		printf("\n");
	}


}
