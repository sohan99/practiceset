#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct  _cellH{
	int data;
	struct _cellH *next;
};

typedef struct _cellH Cell;

Cell * allocateMem(int data);
int lookUp(Cell * Dict[],int data);
void insertTOHash(Cell *Dict[],int data);
void nullify(Cell *Dict[],int);
int deleteHash(Cell *[],int);

int main(){
	
	Cell * Dict[10];
	nullify(Dict,10);
	insertTOHash(Dict,10);
	insertTOHash(Dict,10);
	insertTOHash(Dict,10);
	insertTOHash(Dict,2);
	insertTOHash(Dict,333);
	insertTOHash(Dict,4);
	insertTOHash(Dict,5);
	insertTOHash(Dict,66);
	insertTOHash(Dict,99);
	assert(Dict[0]->data == 10);
	assert(Dict[0]->next == NULL);
	insertTOHash(Dict,1);
	assert(lookUp(Dict,1));
	assert(!lookUp(Dict,3));
	assert(!deleteHash(Dict,3));
	assert(deleteHash(Dict,1));




	return 0;
}
 void nullify(Cell *Dict[],int size){
 	
 	if(Dict != NULL ){
 		int i;
 		for(i=0;i<size;i++)
 			Dict[i] = NULL;
 	}
 }
Cell * allocateMem(int data){
	Cell *temp = (Cell * )calloc(1,sizeof(Cell));
	temp->data = data;
	return temp;
}

int hash(int data){

	return data%SIZE;
}

int lookUp(Cell * Dict[],int data){

	int inex= hash(data);
	Cell * cur = Dict[inex];
	while (cur!= NULL){
		if(cur->data == data){
			return 1;
		}
		cur=cur->next;
	}
	return 0;
}

void insertTOHash(Cell *Dict[],int data){

	int index = hash(data);
	if(!lookUp(Dict,data)){
		Cell *old = Dict[index];
		Dict[index] = allocateMem(data);
		Dict[index]->next = old;
	}
}

int deleteHash(Cell *Dict[],int data){

	if(Dict == NULL) return 0;
	int index = hash(data);
	Cell *cur = Dict[index];
	if(cur->data == data){
		Dict[index] = cur->next;
		free (cur);
		return 1;
	}
	while(cur->next != NULL){
		if(cur->next->data == data){
			Cell *temp = cur->next;
			cur->next =cur->next->next;
			free (temp);
			return 1;
		}
		cur = cur->next;
	}
	return 0;

}
