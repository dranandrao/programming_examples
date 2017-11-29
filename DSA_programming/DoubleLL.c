#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
	struct node* prev;
};

struct node* head;


void insert_element(int element,int position){
	int k=1;
	struct node* tmp = head;
	struct node* newNode = NULL;

	newNode = (struct node*)malloc(sizeof(struct node*));
	newNode->data = element;
	newNode->next=NULL;

	if(position == 1){
		newNode->next = tmp;
		if(tmp)
			tmp->prev = newNode;
		newNode->prev = NULL;
		head = newNode;
		return;
	}

	while((tmp->next != NULL) && (k<position)){
			k++;
			tmp = tmp->next;
	}
	if(k==position){
			newNode->next = tmp;
			newNode->prev = tmp->prev;
			tmp->prev->next = newNode;
			tmp->prev = newNode;
			return;
	}else{
		if((k-position) > 1){
		printf("Cant insert value into that position\n");
		}else{
			tmp->next = newNode;
			newNode->prev = tmp;
		}
		return;
	}
	/*if((k-position) > 1){
		printf("Cant insert value into that position\n");
		return;
	}else{
		if(tmp->next != NULL){
			newNode->next = tmp;
			newNode->prev = tmp->prev;
			tmp->prev->next = newNode;
			tmp->prev = newNode;
		}else{
			tmp->next = newNode;
			newNode->prev = tmp;
		}
		
		return;
	}*/
}

void print(struct node* head){
	struct node* tmp = head;
	while(tmp != NULL){
		printf("%d ",tmp->data);
		tmp = tmp->next;
	}
}

void delete(int position){
	int k = 1;
	struct node* tmp = head;

	if(position == 1){
		if(tmp){
			head = head->next;
			free(tmp);
			head->prev = NULL;
		} else{
			printf("No elements to delete.\n");
		}
		return;
		
	}


	while((tmp->next!= NULL) && (k<position)) {
		k++;
		tmp = tmp->next;
	}

	if((k-position) > 1){
		printf("No element to delete\n");
		return;
	} else {
		tmp->next->prev = tmp->prev;
		tmp->prev->next = tmp->next;
		free(tmp);
		return;
	}
}


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
			insert_element(element,position);
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
