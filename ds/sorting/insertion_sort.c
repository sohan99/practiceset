#include <assert.h>


void insertion_sort_desc(int [],int );
void insertion_sort_asc(int [],int );


int main(){
	
	int a[6] = {1,2,3,4,5,6};
	int i;

	insertion_sort_desc(a,6);
	for(i=0;i<5;i++)
		assert(a[i] < a[i+1]);

	insertion_sort_asc(a,6);
	for(i=0;i<5;i++)
		assert(a[i] > a[i+1]);

	return 0;
}

void insertion_sort_desc(int a[],int n){

	//if(arr == NULL)return 0;

	int i,key,hole;

	for(i=1;i<n;i++){

		key = a[i];
		hole = i;

		while(hole > 0 && a[hole-1] > key ){
			a[hole] = a[hole - 1];
			hole--;
		}
		a[hole] = key;
	}
}

void insertion_sort_asc(int a[],int n){

	//if(arr == NULL)return 0;

	int i,key,hole;

	for(i=1;i<n;i++){

		key = a[i];
		hole = i;

		while(hole > 0 && a[hole-1] < key ){
			a[hole] = a[hole - 1];
			hole--;
		}
		a[hole] = key;
	}
}