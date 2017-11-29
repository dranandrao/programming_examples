#include<stdio.h>
#include<stdlib.h>

struct Qnode{
	int data;
	struct Qnode* next;
};
struct Queue{
	struct Qnode* front,*rear;
};

struct Queue* queue;

struct Qnode* createQunode(int k){
	struct Qnode* tmp = (struct Qnode*)malloc(sizeof(struct Qnode*));
	tmp->data = k;
	tmp->next = NULL;
	return tmp;
}

struct Queue* creteQueue(){
	struct Queue* tmp = (struct Queue*)malloc(sizeof(struct Queue*));
	tmp->front = tmp->rear = NULL;
	return tmp;
}

void enqueue(int item){
	printf("enqueue called");
	struct Qnode* tmp = createQunode(item);

	if(queue->rear == NULL)
	{
		queue->front = queue->rear = tmp;
		return;
	}
	
	queue->rear->next = tmp;
	queue->rear = tmp;
	
}

struct Qnode* dequeue(){
	if(queue->front == NULL){
		return NULL;
	}

	struct Qnode* tmp = queue->front;
	queue->front = queue->front->next;

	if(queue->front == NULL)
	{
		queue->front = queue->rear = NULL;
	}
	
	return tmp;
}

void print(){
	struct Queue* items = queue;
	struct Qnode* tmp = items->rear;

	while(tmp->next!= NULL)
	{
		printf("%d",tmp->data);
		tmp = tmp->next;
	}
}

void main(){
	printf("Queue implimentation");
	queue = creteQueue();
	enqueue(5);
	enqueue(4);
	print();
	struct Qnode* qnode = dequeue();
	if(qnode != NULL){
		printf("%d",qnode->data);
	}
	print();
}
