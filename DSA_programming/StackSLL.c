#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};

struct node* head;

void push(int data){
	struct node* tmp = head;
	struct node* newNode = (struct node*)malloc(sizeof(struct node*));
	newNode->data = data;
	if(tmp != NULL){
		newNode->next = tmp;	
	} else {
		newNode->next = NULL;
	}
	head = newNode;
}

int pop(){
	struct node* tmp = head;
	if(tmp != NULL){
		head = head->next;
		tmp->next = NULL;
		int value = tmp->data;
		free(tmp);	
		return value;
	}
	printf("no element to delete\n");
}
void print(struct node* head){
	struct node* tmp = head;
	while(tmp != NULL){
		printf("%d  ",tmp->data);
		tmp=tmp->next;	
	}
	printf("\n");
}
void main(){
	int choice;
	int element;
	
	
	while(1){
	printf("1)To enter the element\n");
	printf("2)To display the elements in linked list\n");
	printf("3)To delete the element\n");
	printf("Enter your choice\n");
	scanf("%d",&choice);
		switch(choice){
	case 1:	printf("Enter the element to be inserted\n");
			scanf("%d",&element);
			push(element);
			break;
	case 2:	print(head);
			break;
	case 3: printf("popped element : %d\n",pop());
		break;
	default:exit(0);
		}
	}
	
}
