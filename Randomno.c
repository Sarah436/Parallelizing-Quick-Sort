#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

int main(int argc, char *argv[]){
	long n = 10;
	double elapsed_time;
	int numprocs, myid, Root=0;

	printf("HEllo, World!");
	
        /*...MPI Initialisation...*/
        MPI_Init(&argc, &argv);
        MPI_Comm_rank(MPI_COMM_WORLD, &myid);
        elapsed_time = - MPI_Wtime();
         
        scanf ("%ld", &n);
	FILE *fp;
	fp = fopen("random.txt", "W+") ;
	srand(time(0));
	  
	for (long i=0;i<n;i++){
	    fprintf(fp,"%d\n" , rand()%10000);
	}
	fclose(fp);
	  
	printf("Done! \n") ;
	elapsed_time+=MPI_Wtime();
	printf ("Time taken = %f\n" , elapsed_time) ;

        MPI_Finalize();
	
	return 1;
}