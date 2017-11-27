#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

bool wantp = false, wantq = false;
int turn = 1;
int count1=0, count2=0;
int a=0, b=0;
void *p() {
	while(1) {
		printf("NCSp\n");
		wantp = true;
		while(wantq != false) {
			if(count1<3){
				if (turn == 2) {
					wantp = false;
					while(turn != 1) {
						printf("p waits\n");
						sleep(1);
					}
					wantp = true;
				}
			}
			else{
				wantp = false;
				printf("p waits\n");
				wantp = true;
				a++;
				if(a>5){
					a=0; count1=0;
					sleep(1);
					break;
				}
				sleep(1);
			}
		}
		{
			printf("CSp\n");
			sleep(1);
		}
		printf("p left CS\n");
		turn = 2;
		wantp = false;
		count1++;
	}
	pthread_exit(NULL);
}

void *q() {
	while(1) {
		printf("NCSq\n");
		wantq = true;
		while(wantp != false) {
			if(count2<3){
			if (turn == 1) {
				wantq = false;
				while(turn != 2) {
					printf("q waits\n");
					sleep(1);
				}
				wantq = true;
			}}
			else{
				wantq = false;
				printf("q waits\n");
				wantq = true;
				b++;
				if(b>5){
					b=0; count2=0;
					sleep(1);
					break;
				}
				sleep(1);
			}
		}
		{
			printf("CSq\n");
			sleep(1);
		}
		printf("q left CS\n");
		wantq = false;
		turn = 1;
		count2++;
	}
	pthread_exit(NULL);
}

int main() {
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, p, NULL);
	pthread_create(&thread2, NULL, q, NULL);
	pthread_exit(NULL);
	return 0;
}