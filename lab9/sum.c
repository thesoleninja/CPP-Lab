#include<stdio.h>
#include <omp.h>
#define MAX 100

int main(){

int sum=0, i;

 #pragma omp parallel for
 for (i=1;i<= MAX; i++) {
  // #pragma omp atomic
     sum += i;
  }


 printf("Sum : %d\n",sum);

}