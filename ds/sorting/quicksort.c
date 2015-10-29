#include <assert.h>
#include<stdio.h>

void swap(int a, int b);
void quicksort(int arr[], int start, int end);
int partition(int arr[], int start, int end);


int main(){

	int arr[6] = {1,9,2,8,3,7};
	int i;

	quicksort(arr,0,5);

	for(i=0;i<5;i++){
		assert(arr[i]<arr[i+1]);
		printf(" %d ",arr[i]);
	}
	printf(" %d  ",arr[i]);

	return 0;
}


void quicksort(int arr[], int start, int end){
	int pindex;
	if(start < end){
		pindex = partition(arr,start,end);
		quicksort(arr,start,pindex-1);
		quicksort(arr,pindex+1,end);
	}
}

int partition(int arr[], int start, int end){
	// let pivot element be the last array element
	// pindex wii be the index of the pivot element at the last 
	int pivot = arr[end];
	int pindex = start;

	int i,temp;

	// move all the element less than pivot element to left 
	for(i=start;i<end;i++){	
		if(arr[i] <= pivot){
			temp = arr[i];
			arr[i] = arr[pindex];
			arr[pindex] = temp;
			pindex++;
		}

	}
	//swap the pivot element to its position

	temp = arr[pindex];
	arr[pindex] = arr[end];
	arr[end] = temp;

	return pindex;
}


