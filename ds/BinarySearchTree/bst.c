#include <assert.h>
#include <stdlib.h>


struct _node_
{
	int value;
	struct _node_ *lchild;
	struct _node_ *rchild;
};

typedef struct _node_ Node;

Node * insertNode_rec(Node *, int );
Node * insertNode(Node *, int );
Node * allocateMemory(int);
Node * findMinRightleftmost(Node *);
Node * deleteElement(Node * root);
Node * delete_node( Node * treeHead, int element);
int main(){

	Node *head = NULL;
	head = insertNode_rec(head,10);
	head = insertNode_rec(head,9);
	head = insertNode_rec(head,11);
	head = insertNode_rec(head,10);
	assert(head->value == 10);
	assert(head->lchild->value == 9);
	assert(head->rchild->value == 11);


	Node *head2 = NULL;
	head2 = insertNode(head2,10);
	head2 = insertNode(head2,9);
	head2 = insertNode(head2,11);
	head2 = insertNode(head2,3);
	head2 = insertNode(head2,9);
	head2 = insertNode(head2,4);
	head2 = insertNode(head2,14);
	head2 = insertNode(head2,12);
	head2 = insertNode(head2,16);
	assert(head2->value == 10);
	assert(head2->lchild->value == 9);
	assert(head2->rchild->value == 11);
	Node * temp = findMinRightleftmost(head2->rchild);
	assert(temp);
	assert(temp->value == 11);


	head2 = delete_node(head2,14);
	assert(head2->rchild->value == 11);
	assert(head2 ->rchild->rchild->value == 16
		);

	return 0;
}

Node * allocateMemory(int value){
	Node * temp = (Node *)calloc(1,sizeof(Node));
	temp->value = value;
	return temp;
}
/* function will insert into the tree reccursive ly */

Node * insertNode_rec(Node *treeHead, int value){
	if(treeHead == NULL){
		treeHead = allocateMemory(value);
	}else{

		if(value < treeHead->value)
			treeHead->lchild = insertNode_rec(treeHead->lchild,value);
		else if(value > treeHead->value)
			treeHead->rchild = insertNode_rec(treeHead->rchild,value);
	}
	return treeHead;
}

/* this is a non recursive function to insert into the array */
Node * insertNode(Node *treeHead, int value){
	
	// initially if tree is empty
	if(treeHead == NULL){
		treeHead = allocateMemory(value);
		return treeHead;
	}

	// if tree is not empty take the copy of root address to return 
	Node * temp = treeHead;
	//loop till u get the itended position
	while(treeHead != NULL){

		if(value < treeHead->value){
			// if child empty insert he value and exit the loop
			if(!treeHead->lchild){
				treeHead->lchild = allocateMemory(value);
				break;
			}
			treeHead = treeHead->lchild;

		}
		else if(value > treeHead->value){
			// if child empty insert he value and exit the loop
			if(!treeHead->rchild){
				treeHead->rchild = allocateMemory(value);
				break;
			}
			treeHead = treeHead->rchild;
		}// if the value == to the element do nothing
		else 
			break;
	}

	return temp;
}

Node * findMinRightleftmost(Node *treeHead){
	if(treeHead!=NULL){
		while(treeHead->lchild)
			treeHead = treeHead->lchild;
	}
	return treeHead;
}

Node * delete_node( Node * treeHead, int element){

	if(!treeHead) return treeHead;

	if(treeHead->value >element)
		treeHead->lchild = delete_node(treeHead->lchild,element);
	else if(treeHead->value <element)
		treeHead->rchild = delete_node(treeHead->rchild,element);
	else 
		 treeHead = deleteElement(treeHead);

	return treeHead;

}

Node * deleteElement(Node * root){

	if(!(root->lchild)){
		Node * temp = root->rchild;
		free(root);
		return temp;
	}
	else if(!(root->rchild)){
		Node * temp = root->lchild;
		free(root);
		return temp;
	}
	else {
		Node *temp = findMinRightleftmost(root->rchild);
		root->value = temp->value;
		root->rchild = delete_node(root->rchild, temp->value);
		return root;
	}
}


/*Node * delete_node( Node * treeHead, int element){

	if(treeHead == NULL) return treeHead;
	printf("treeHead = %d \n", treeHead->value);
	if(treeHead->value >element)
		treeHead->lchild = delete_node(treeHead->lchild,element);
	else if(treeHead->value <element)
		treeHead->rchild = delete_node(treeHead->rchild,element);
	else 
	{
		if(treeHead->lchild == NULL){
			Node *temp = treeHead->rchild;
			free(treeHead);
			return	temp;
		}
		if(treeHead->rchild == NULL){
			Node *temp = treeHead->lchild;
			free(treeHead);
			return temp;
		}
		Node *temp = findMinRightleftmost(treeHead->rchild);
		
		printf("inside else \n");

		treeHead->value = temp->value;
		treeHead->rchild = delete_node(treeHead->rchild,temp->value);
		
	}
return treeHead;
}*/
