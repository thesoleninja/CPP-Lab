#include<stdio.h>
#include <omp.h>

int main(){
    #pragma omp parallel
    {
    int     ID = omp_get_thread_num();
    printf("This identifier : %d\n", ID);

}
}

