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

	if(rank==root){

		srctag=0;

		for(i=1;i<numofprocs;i++){
			src=i;
			MPI_Recv(&value,1,MPI_INT,src,srctag,MPI_COMM_WORLD,&status);
			sum+=value;
			printf("\nProcess %d has sent the message : M_%d\n",i,value);
		}

		//printf("\nSUM is : %d \n",sum);

	}


	MPI_Finalize();
}