#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<signal.h>
int wantp=0,wantq=0;

void * p(){
    while(1){
        wantp=1;
        while(wantq){
            wantp=0;
            wantp=1;
        }
        printf("1");
        wantp=0;
    }
}

void * q(){
    while(1){
        wantq=1;
        while(wantp){
            wantq=0;
            wantq=1;
        }
        printf("2");
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