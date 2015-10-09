#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct _node_{

	int value;
	struct _node_ *front;
	struct _node_ *rear;
};

typedef struct _node_ Node;


Node * insertNodeAtFront(Node *,int);
Node * insertNodeAtEnd(Node *, int);
Node * insertNodeAtPos(Node * head,unsigned int, int );
Node * deleteAtTheEnd(Node *);
Node * deleteAtTheFront(Node *);

Node * allocateMemory();


int main(){

	Node * head = allocateMemory();
	/* check allocate memory is good*/
	assert(head != NULL);
	assert(head->front == NULL);
	assert(head->rear == NULL);
	assert(head->value == 0);
	free(head);
	head = NULL;

	/* check for inserting on empty list*/
	head = insertNodeAtFront(head, 1);
	assert(head->front == NULL);
	assert(head->rear == NULL);
	assert(head->value == 1);

	/*check for inerting at end */
	head = insertNodeAtFront(head, 20);
	assert(head != NULL);
	assert(head->value == 20);
	assert(head->front != NULL);
	assert(head->front->front == NULL);
	assert(head->front->value == 1);
	assert(head->front->rear == head);

	head = insertNodeAtEnd(head, 30);
	assert(head->front->front != NULL);
	assert(head->front->front->rear == head->front);
	assert(head->front->front->front == NULL);
	assert(head->front->front->value == 30);

	


	head = deleteAtTheEnd(head);
	assert(head->front->front == NULL);
	assert(head->front->rear == head);

	head = deleteAtTheFront(head);
	assert(head!=NULL);
	assert(head->value == 1);
	assert(head->rear == NULL);

	head = deleteAtTheFront(head);
	assert(head == NULL);

	head = insertNodeAtEnd(head, 30);
	head = deleteAtTheEnd(head);
	assert(head == NULL);


	head = insertNodeAtPos(head,2,20);

	head = insertNodeAtEnd(head, 10);
	head = insertNodeAtEnd(head, 20);
	//head = insertNodeAtEnd(head, 30);
	head = insertNodeAtPos(head,2,25);// there are 3 elemnts in this point 
	head = insertNodeAtPos(head,4,40);

	assert(head->value == 10);
	assert(head->front->value == 25);
	assert(head->front->front->value == 20);
	assert(head->front->front->front->value == 40);






	return 0;
}

 Node * allocateMemory(){
  	return (Node *)calloc(1,sizeof(Node));
 }

 Node * insertNodeAtFront(Node * head,int value){
 	Node *newNode = NULL;
 	if(head != NULL){
 		newNode = allocateMemory();	// create a new node
 		if(newNode != NULL){
 									// set the pointer front and back
 			newNode->front = head;
 			newNode->value = value;
 			head->rear = newNode; 	//head's rear should point to the newnode
 		}
 		return newNode;
 	}
 	//Else part
 	head = allocateMemory();
 	if(head != NULL)
 		head->value = value;

 	return head;
 }

Node * insertNodeAtEnd(Node * head, int value){
	Node *newNode = NULL;
	Node *temp = NULL;
	if(head == NULL){
		head = allocateMemory();
	 	if(head != NULL)
	 		head->value = value;
	}
	else {
		temp = head;
		while( temp->front != NULL)
			temp = temp->front;

		newNode = allocateMemory();
		if(newNode != NULL){
			newNode->rear = temp;
			newNode->value = value;
			temp->front = newNode;
		}
	}
	return head;
}



Node * deleteAtTheEnd(Node * head){
	Node *temp = NULL;
	if(head != NULL){
		temp = head;
		
		while(temp->front != NULL)
			temp=temp->front;
		
		if(temp->rear != NULL)
			temp->rear->front = NULL;
		else 
			head = NULL;
		
		free(temp);
	}
	return head;
}

Node * deleteAtTheFront(Node * head){
	if(head != NULL){
		if(head->front == NULL)
		{
			free(head);
			head = NULL;
		}
		else{
			head=head->front;
			free(head->rear);
			head->rear = NULL;
		}
	}
	return head;
}

Node * insertNodeAtPos(Node * head,unsigned int pos, int value){
	/* this finction allows you to add at position on 0 and n+1  */
	Node *temp = head;
	Node *newNode = NULL;
	int i = 2;
	if(head != NULL){
		if( pos == 0 || pos == 1 ){
			newNode = allocateMemory();
			newNode->value = value;
			newNode->front = head;
			head->rear = newNode;
		}
		else {
			for(;i<pos && (temp->front != NULL);i++,temp=temp->front);
			if(i == pos){
				newNode = allocateMemory();
				newNode->value = value;
				newNode->front = temp->front;
				newNode->rear = temp;
				temp->front = newNode;
				printf("here");
			}
		}
	}

	return head;
}