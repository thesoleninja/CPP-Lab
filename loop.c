#include<stdio.h>
#include <omp.h>
#define MAX 5

int main(){
int i, A[] = {1,2,3,4,5}, B[] = {1,1,1,1,1};
 #pragma omp parallel for
 for (i=0;i< MAX; i++) {
#pragma omp atomic
  A[i] = A[i] + B[i];
 }

 for(i=0; i<MAX; i++){
  printf("%d\n",A[i]);
 }
}