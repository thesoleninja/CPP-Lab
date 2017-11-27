#include<stdio.h>
#include<pthread.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#include<signal.h>
#include<unistd.h>
int turn = 1;

bool flag1 = false;
bool flag2 = false;

void * threadFunc1(void* a){
	while(true){
         flag1 = true;
		 turn = 2;
         while (flag2 == true && turn == 2){printf("process 1 is waiting............\n");sleep(1);}
         // critical section
         printf("Process 1 entered critical section!\n");
         printf("Process 1 completed critical section!\n");
         // end of critical section
         flag1 = false;

	}
}

void * threadFunc2(void* a){
	while(true){
         flag2 = true;
		 turn = 1;
         while (flag1 == true && turn == 1){printf("process 2 is waiting............\n");sleep(1);}
         // critical section
         printf("Process 2 entered critical section!\n");
         printf("Process 2 completed critical section!\n");
         // end of critical section
         flag2 = false;

	}
}

void main(){
    pthread_t thread[2];
    int num1 = 1, num2 = 2;

    int check1, check2;

    check2 = pthread_create(&thread[1], NULL, threadFunc2, &num2);
    check1 = pthread_create(&thread[0], NULL, threadFunc1, &num1);

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