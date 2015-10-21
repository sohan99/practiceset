#include <assert.h>
#include <stdio.h>
void buble_sort_desc(int [],int );
void buble_sort_asc(int [],int );

int main(){
	int i;
	//int arr[6] = {6,5,4,3,2,1};
	int arr[6] = {1,4,3,2,5,6};
	buble_sort_desc(arr,6);

	for(i=0;i<5;i++)
		assert(arr[i] > arr[i+1]);

	buble_sort_asc(arr,6);

	for(i=0;i<5;i++)
		assert(arr[i] < arr[i+1]);

	return 0;
}

void buble_sort_desc(int a[],int n){

	int i,k,temp;
	int already_sorted_flag = 1;
	// repeat the swapping process till n elements
	for(k=0;k<n-1;k++){

		already_sorted_flag = 1;
		// push the lowest to the right corner of the array
		for(i=0;i<n-k-1;i++){
			//check each element and swap
			if(a[i]<a[i+1]){
				//set flag that it is not sorted
				already_sorted_flag = 0;
				//swap a[i] and a[i+1]
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
			}
		}
		if(already_sorted_flag) break;
	}
}

void buble_sort_asc(int a[],int n){

	int i,k,temp;
	int already_sorted_flag = 1;
	// repeat the swapping process till n elements
	for(k=0;k<n-1;k++){

		already_sorted_flag = 1;
		// push the largest to the right corner of the array
		for(i=0;i<n-k-1;i++){
			//check each element and swap
			if(a[i]>a[i+1]){
				//set flag that it is not sorted
				already_sorted_flag = 0;
				//swap a[i] and a[i+1]
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
			}
		}
		if(already_sorted_flag) break;
	}
}