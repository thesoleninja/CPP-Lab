#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<signal.h>
int wantp=0,wantq=0;
int sig = 0;
void sig_handler(int signo)
{
  	if (signo == SIGINT){
	    	printf("received SIGINT\n");
	    	sig = 1;
    	}
}
void * p(){
    while(1){
        printf("NCS of P\n");
        sleep(1);
        while(wantq);
        wantp=1;
        if(wantp==1 && wantq==1){
            printf("Both processes want to execute their critical sections, i.e, M.E.\n");
            exit(0);
        }
        printf("Process 1 in CS\n");
        wantp=0;
    }
}

void * q(){
    while(1){
        printf("NCS of Q\n");
        sleep(1);
        while(wantp);
        if (sig)
            while(!wantp);
        wantq=1;
        if(wantp==1 && wantq==1){
            printf("Both processes want to execute their critical sections, i.e, M.E.\n");
            exit(0);
        }
        printf("Process 2 in CS\n");
        wantq=0;
    }
}

void main(){
    pthread_t t1,t2;
    int c1=pthread_create(&t1, NULL, p, NULL);
    int c2=pthread_create(&t2, NULL, q, NULL);
    if (signal(SIGINT, sig_handler) == SIG_ERR)
  		printf("\ncan't catch SIGINT\n");
    if( c1)
    {
        printf("Error: thread not created!\n");
	    exit(-1);
    }
    if(c2)
    {
        printf("Error: thread not created!\n");
	    exit(-1);
    }
    pthread_exit(NULL);
}