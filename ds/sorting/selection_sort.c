#include <assert.h>
#include <stdio.h>
void selection_sort_desc(int [], int );
void selection_sort_asc(int [], int );

int main(){

	int arr[6] = {6,5,4,3,2,1};
	int i;
	selection_sort_asc(arr,6);
	for(i=0;i<5;i++){
		assert(arr[i] < arr[i+1]);
	}

	selection_sort_desc(arr,6);
	for(i=0;i<5;i++){
		assert(arr[i] > arr[i+1]);
	}

	return 0;
}

void selection_sort_asc(int a[], int n){

	int i, j, temp, min;
	

	for(i=0; i < n-1; i++){
		min = i;
		for(j=i+1;j<n;j++){
			if(a[j] < a[min]){
				min = j;
			}
		}
		if(i != min){
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
	}
}

void selection_sort_desc(int a[], int n){

	int i, j, temp, max;
	

	for(i=0; i < n-1; i++){
		max = i;
		for(j=i+1;j<n;j++){
			if(a[j] > a[max]){
				max = j;
			}
		}
		if(i != max){
			temp = a[i];
			a[i] = a[max];
			a[max] = temp;
		}
	}
}	