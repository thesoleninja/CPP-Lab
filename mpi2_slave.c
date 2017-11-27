#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>


int main(int argc,char *argv[]){

	int rank,numofprocs,root=0;
	int src,dest;
	int value,i,sum;
	int srctag,desttag;
	MPI_Status status;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&numofprocs);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);


	if(rank!=root){

		desttag=0;
		MPI_Send(&rank,1,MPI_INT,root,desttag,MPI_COMM_WORLD);

	}

	MPI_Finalize();
}