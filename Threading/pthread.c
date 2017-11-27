#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<signal.h>

void sighandler(int signum)
{
   printf("Caught signal %d, coming out...\n", signum);
}


int main(){
	int time=0,i=1;
	pid_t pid;
	signal(SIGINT, sighandler);
	
	
	while(1){
		printf("\nWait for 1 second to see process id : \n");
		sleep(1);
		printf("\nsleep time %d",++time);
		
		fork();
		
	  	printf("\nThe process id is %d", getpid());
	}
	
   	return 0;
}
