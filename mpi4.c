#include<stdio.h>
#include<mpi.h>

int main(int argc, char *argv[])
{
    int	MyRank, Numprocs;
    int	value, i;
    int	Source, Source_tag, Destination, Destination_tag=0;
    int ROOT = 0;
    MPI_Status status;


    int sum = ROOT;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &Numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &MyRank);

    if (MyRank == 0)
    {
	       Source_tag = 0;

	       for(i=1; i<Numprocs; i++){
	            Source = i;
	            MPI_Recv(&value, 1, MPI_INT, Source, Source_tag, MPI_COMM_WORLD, &status);
	            sum+=value;
	            printf("#Process%d sent %d\n",i,value);
	       }
	       printf("Sum : %d\n",sum);
    }

    else
    {
        MPI_Send(&MyRank, 1, MPI_INT, ROOT, Destination_tag, MPI_COMM_WORLD);
    }

    MPI_Finalize();
}