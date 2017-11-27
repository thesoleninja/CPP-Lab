#include<stdio.h>
#include<pthread.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#include<signal.h>
#include<unistd.h>
int turn = 2;
bool sig = false;
void sig_handler(int signo)
{
  	if (signo == SIGINT){
	    	printf("received SIGINT\n");
	    	sig = true;
    	}
}
void * threadFunc1(void* a){
	while(true){

		while( turn == 2 ){}
		//critical code section
			printf("Process %d in critical section.\n",1);
			sleep(1);
		//end
		turn = 2;
	}
}

void * threadFunc2(void* a){
	while(true){

		while( turn == 1 ){}
		//critical code section
			printf("Process %d in critical section.\n", 2);
			sleep(1);
		//end
		if(sig == false)
		turn = 1;
	}
}

void main(){
	printf("%d",SIGABRT);
    pthread_t thread[2];
    int num1 = 1, num2 = 2;

    int check1, check2;

    check2 = pthread_create(&thread[1], NULL, threadFunc2, &num2);
    check1 = pthread_create(&thread[0], NULL, threadFunc1, &num1);
    if (signal(SIGINT, sig_handler) == SIG_ERR)
  		printf("\ncan't catch SIGINT\n");
    if(check1){
        printf("Error: thread not created!\n");
	    exit(-1);
    }

    if(check2){
        printf("Error: thread not created!\n");
	    exit(-1);
    }
    pthread_exit(NULL);
}
