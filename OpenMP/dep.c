#include<stdio.h>
#include <omp.h>
#define MAX 10

int foo(int d){
 return (d*2);
}


int main(){

int i,  A[MAX];
 int dependency = 1;
 #pragma omp parallel for
 for (i=0;i< MAX; i++) {

   dependency += 1;
#pragma omp critical
   A[i] = foo(dependency);  //any function on dependency
 }

 for (i=0;i< MAX; i++) {
  printf("%d\n",A[i]);
 }
}