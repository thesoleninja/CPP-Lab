#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>

void Merge(int *A,int *L,int leftCount,int *R,int rightCount) {
	int i,j,k;

	i = 0; j = 0; k =0;

	while(i<leftCount && j< rightCount) {
		if(L[i]  < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	while(i < leftCount) A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
}

void MergeSort(int *A,int n, sem_t sem) {
	sem_t s;
	sem_init(&s, 0, 0);
	int mid,i, *L, *R;
	if(n < 2) return;

	mid = n/2;

	L = (int*)malloc(mid*sizeof(int));
	R = (int*)malloc((n- mid)*sizeof(int));

	for(i = 0;i<mid;i++) L[i] = A[i];
	for(i = mid;i<n;i++) R[i-mid] = A[i];

	MergeSort(L,mid,sem);
	sem_wait(&s);
	MergeSort(R,n-mid,sem);
	sem_wait(&s);
	Merge(A,L,mid,R,n-mid);
        free(L);
        free(R);
}

int main() {

	int A[] = {5,4,3,2,1};
	int i,numberOfElements;
	sem_t sem;
	numberOfElements = sizeof(A)/sizeof(A[0]);

	MergeSort(A,numberOfElements, sem);

	for(i = 0;i < numberOfElements;i++) printf("%d ",A[i]);
	return 0;
}