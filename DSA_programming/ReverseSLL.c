#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
struct node* head;
void reverse_list(){
	struct node* tmp = head;
	struct node* prev = NULL,*next = NULL;

	while(tmp != NULL){
		next = tmp->next;
		tmp->next = prev;
		prev = tmp;
		tmp = next;
	}
	head = prev;
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
	struct node* first = (struct node*)malloc(sizeof(struct node*));
	struct node* second = (struct node*)malloc(sizeof(struct node*));
        struct node* third  = (struct node*)malloc(sizeof(struct node*));

	first->data = 3;
	second->data = 4;
	third->data = 1;
	
	head = first;
	first->next = second;
	second->next = third;
	third->next = NULL;

	reverse_list();
	print(head);
}
