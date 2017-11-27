#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<signal.h>
int gate=0;

void * p(void * k){
    int *j = (int *)k;
    int i = *j;
    while(1){
        printf("NCS %d\n",i);
        while(1){
            while(gate!=0){
                gate=i;
             //x   sleep(2);
            }
            if(gate!=i)
                break;
        }
        printf("CS %d\n",i);
        gate=0;
    }
}
main(){
    pthread_t t[5];
    int i;
    for(i=0; i<5; i++){
        pthread_create(&t[i], NULL, p, &i);
    }
    pthread_exit(NULL);
}