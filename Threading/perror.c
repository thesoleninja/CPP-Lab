#include<stdio.h>
#include<stdlib.h>
#include<error.h>
int main(int argc,char *argv[])	
{
	FILE *fp;
	fp = fopen(argv[1], "r");
	if(fp==NULL)
		perror("File Open");

	else
		printf("Successful");
}
