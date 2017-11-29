#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};

struct node* head = NULL;

void insertElement(int element,int position){
	int k=1;
	struct node* tmp = head;
	struct node* prev = NULL;
	struct node* newNode;

	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = element;

	if(!newNode) {
		printf("No memory");
		exit(0);
	}
	
	if(position == 1){
		newNode->next = head;
		head = newNode;
		return;
	}
	
	while(tmp != NULL && k<position){
		prev = tmp;
		tmp = tmp->next;
		k++;
	}
	
	if((k-position) > 1){
		printf("Entered position is not accessible");
		exit(0);	
	}else{
		newNode->next = tmp;
		prev->next = newNode;
	}

}

void delete(int position){
	int k=1;
	struct node* temp = head;
	struct node* prev = NULL;

	if(temp == NULL){
		printf("No elements to delete\n");
		return;
	}

	if(position == 1){
		head = head->next;
		free(temp);
		return;
	}

	while(temp != NULL && k<position){
		k++;
		prev = temp;
		temp = temp->next;
	}

	if(k != position){
		printf("There is no element in that position\n");
		return;
	}else {
		prev->next = temp->next;
		free(temp);
	}

}
void print(struct node* head);


void main(){
	int choice;
	int element;
	int position;
	
	
	while(1){
		printf("1)To enter the element\n");
	printf("2)To display the elements in linked list\n");
	printf("3)To delete the element\n");
	printf("Enter your choice\n");
	scanf("%d",&choice);
		switch(choice){
	case 1:	printf("Enter the element to be inserted\n");
			scanf("%d",&element);
			printf("Enter the position\n");
			scanf("%d",&position);
			insertElement(element,position);
			break;
	case 2:	print(head);
			break;
	case 3: printf("Enter the position\n");
			scanf("%d",&position);
			delete(position);
			break;
	default:exit(0);
		}
	}
	

}

void print(struct node* head){
	struct node* tmp = head;
	while(tmp != NULL){
		printf("%d  ",tmp->data);
		tmp=tmp->next;	
	}
	printf("\n");
}


