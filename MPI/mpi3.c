#include<stdio.h>
#include "mpi.h"

int main(int argc, char *argv[]){
    int COUNT=1, COMM = MPI_COMM_WORLD, SOURCE_TAG=0, DESTINATION_TAG=0, DESTINATION =0, sum=0;
    int source, MyRank, no_of_processes, value;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(COMM, &no_of_processes);
    MPI_Comm_rank(COMM, &MyRank);

    if(MyRank == 0){

        for (source=1; source<no_of_processes; source++){

            MPI_Recv(&value, COUNT, MPI_INT, source, SOURCE_TAG, COMM, &status);
            printf("Value received from Process : %d\n",source);
            sum += value;
        }
        printf("Sum = %d\n",sum);
    }
    else
        MPI_Send( &MyRank, COUNT, MPI_INT, DESTINATION, DESTINATION_TAG, COMM ) ;

    MPI_Finalize();

}