#include <assert.h>
#include <stdio.h>

void merge(int arr[],int start,int mid,int end);
void merge_sort(int arr[],int start, int end);

int main(){
	int arr[]={1,2,4,3,5,6};
	int i;
	merge_sort(arr,0,5);

	for(i=0;i<5;i++)
		assert(arr[i]<arr[i+1]);

	return 0;
}


void merge_sort(int arr[],int start, int end){
	int mid;
	if(start < end){

		mid = (	start+end)/2;
		merge_sort(arr,start,mid);
		merge_sort(arr,mid+1,end);
		merge(arr,start,mid,end);
	}
}


void merge(int arr[],int start,int mid,int end){

	//int tem[end+1];
	int i,j,k;
	int temp[12];
	i=start;
	j=mid+1;
	k=start;

	while (i <= mid && j <= end){
		if(arr[i] < arr[j]){
			temp[k++]=arr[i++];
		}
		else {
			temp[k++]=arr[j++];
		}
	}
	while (i <= mid){
		temp[k++]=arr[i++];
	}
	while (j <= end){
		temp[k++]=arr[j++];
	}

	for(i=start;i<=end;i++){
		arr[i]=temp[i];
		// will show what is sorted ;; for understanding
		printf(" %d ",temp[i]);
	}
	printf("\n");

}