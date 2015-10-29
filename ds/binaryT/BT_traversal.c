#include <assert.h>
#include <stdio.h>
#include <stdlib.h>




struct _node
{
	/* data */
	int value;
	struct _node * lc;
	struct _node * rc;
};

typedef struct _node Node;

struct _queve_ {
	Node *add[20];
	int head,tail,size;
};

void insertq (struct _queve_ *q , Node * add);
Node * removeq (struct _queve_ *q );

Node *allocateMem(int value);
void preOrder(Node *root);
void postOrder(Node * root);
void inOrder(Node *root);
void levelOrder(Node *root,struct _queve_ *q);


int main(){

	Node *root = allocateMem(10);
	root->rc = allocateMem(15);
	root->lc = allocateMem(5);
	root->lc->lc = allocateMem(4);
	root->lc->rc = allocateMem(6);
	root->rc->lc = allocateMem(14);
	root->rc->rc = allocateMem(16);

	preOrder(root);
	printf("\n");
	inOrder(root);
	printf("\n");
	postOrder(root);
	printf("\n");

	struct _queve_ q;
	q.head = 0;
	q.tail = -1;
	q.size = 20;

	insertq(&q,root);
	levelOrder(root,&q);
	printf("\n");


	return 0;
}

Node *allocateMem(int value){

	Node *temp = (Node *)calloc(1,sizeof(Node));
	temp->value = value;
	return temp;

}

void preOrder(Node *root){

	if(!root)return;
	printf(" %d ",root->value);
	preOrder(root->lc);
	preOrder(root->rc);
}

void postOrder(Node * root){

	if(!root) return;
	postOrder(root->lc);
	postOrder(root->rc);
	printf(" %d " ,root->value);
}


void inOrder(Node *root){

	if(!root) return;
	inOrder(root->lc);
	printf(" %d ", root->value);
	inOrder(root->rc);
}


void levelOrder(Node *root,struct _queve_ *q){
	
	if(!root)   return;
	Node *temp = removeq(q);
	printf(" %d ",temp->value);
	insertq(q,temp->lc);
	insertq(q,temp->rc);
	levelOrder(temp->lc,q);
	levelOrder(temp->rc,q);
}

/* function used in level order to store value */
void insertq (struct _queve_ *q , Node * add){

	if(q->tail < q->size - 1)
		q->add[++q->tail] = add;
}

Node * removeq (struct _queve_ *q ){
	Node *temp = NULL;
	if(q->head <= q->tail)
		temp = q->add[q->head++];
	if(q->tail < q->head)
	{	q->head = 0;
		q->tail = -1;
	}
	return temp;
}