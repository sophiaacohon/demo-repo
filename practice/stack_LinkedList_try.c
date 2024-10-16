/*
Linked List Implementation of Stack
By: Sophia Cohon
March 21, 2023
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* head;
struct node* tail;

void push(int n){
	struct node* temp;
	struct node* ptr = head;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = n;
	temp->next = NULL;
	if(head == NULL){
		head = temp;
		return;
	}
	else{
		while(ptr->next!=NULL){
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
}

void pop(){
	struct node* prev_ptr = NULL;
	struct node* ptr;
	ptr = head;
	if(head == NULL){
		printf("Stack Underflow");
		return;
	}
	else{
		while(ptr->next!=NULL){
			prev_ptr = ptr;
			ptr = ptr->next;
		}
		prev_ptr->next = ptr->next;
		free(ptr);
	}
}

void display(){
	struct node* ptr = head;
	if(head == NULL){
		printf("Stack is Empty\n");
	}
	else{
		while(ptr!=NULL){
			printf("%d\n", ptr->data);
			ptr = ptr->next;
		}
	}
}

void main(){
	int choice, n;
	do{
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Display\n");
		printf("Enter choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Enter a number: ");
				scanf("%d", &n);
				push(n);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
		}
	}while(choice!=0);
}
