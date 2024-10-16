#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* prev;
	struct node* next;
};

void display(struct node* ptr);

int main(){
	struct node* head;
	struct node* first;
	struct node* second;
	struct node* third;
	struct node* fourth;
	
	first = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	third = (struct node*)malloc(sizeof(struct node));
	fourth = (struct node*)malloc(sizeof(struct node));
	
	first->data = 10;
	second->data = 20;
	third->data = 30;
	fourth->data = 40;
	
	first->next = second;
	first->prev = NULL;
	second->next = third;
	second->prev = first;
	third->next = fourth;
	third->prev = second;
	fourth->next = NULL;
	fourth->prev = third;
	
	head = first;
	
	display(first);
	
	return 0;
}

void display(struct node* ptr){
	struct node* last;
	printf("The doubly linked list elements are:\n");
	while(ptr!=NULL){
		printf("%d ", ptr->data);
		last = ptr;
		ptr = ptr->next;
	}
	printf("\n");
	
	//my modification yehey
	printf("The doubly linked list in reverse:\n");
	while(last!=NULL){
		printf("%d ", last->data);
		last = last->prev;
	}
}
