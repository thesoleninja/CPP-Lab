#include<stdio.h>
#include"mpi.h"

int main(int argc,char *argv[])
{
    int iproc;
    int MyRank, Numprocs, Root = 0;
    int  sum = 0;
    int	SOURCE =0 , SOURCE_TAG=0;
    int Destination, Destination_tag;
    int msg = 13;
    int value;
    int COUNT = 1, ROOT=0;
    MPI_Status status;

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&Numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD,&MyRank);

    MPI_Bcast( &msg, COUNT, MPI_INT , ROOT, MPI_COMM_WORLD);

    // if( MyRank ==0){
        // MPI_Recv(&value, COUNT, MPI_INT, SOURCE, SOURCE_TAG, MPI_COMM_WORLD, &status);
        printf("%d %d\n",MyRank,msg);
    // }
    MPI_Finalize();
}