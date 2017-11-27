#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<signal.h>
#include<semaphore.h>
sem_t s ;


void * p(void * k){
    int *j = (int *)k;
    int i = *j;
    while(1){
        sleep(2);
        printf("Process %d : NCS\n",i);
        sem_wait(&s);
        sleep(1);
        printf("Process %d : Critical Section.\n",i);
        sem_post(&s);
       //sleep(1);
    }
}
void main(){
    sem_init(&s, 0, 1);
    pthread_t t[5];
    int i;
    for(i=0; i<5; i++){
        pthread_create(&t[i], NULL, p, &i);
    }
    pthread_exit(NULL);
}