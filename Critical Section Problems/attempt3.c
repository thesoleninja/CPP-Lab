#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<signal.h>
int wantp=0,wantq=0;

void * p(){
    while(1){
        sleep(1);
        wantp=1;
        printf("NCSp, TRUEp\n");
        while(wantq);
        printf("Process 1 is in CS\n");
        wantp=0;
    }
}

void * q(){
    while(1){
        sleep(1);
        wantq=1;
        printf("NCSq, TRUEq\n");
        while(wantp);
        printf("Process 2 is in CS\n");
        wantq=0;
    }
}

void main(){
    pthread_t t1,t2;
    int c1=pthread_create(&t1, NULL, p, NULL);
    int c2=pthread_create(&t2, NULL, q, NULL);
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