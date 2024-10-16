#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

void insert_begin(struct Node** head, int nd){
	struct Node* bago = (struct Node*)malloc(sizeof(struct Node));
	bago->data = nd;
	bago->next = *head;
	(*head) = bago;
}

void insert_end(struct Node** head, int nd){
	struct Node* bago = (struct Node*)malloc(sizeof(struct Node));
	struct Node* last = *head; //the one that traverses through the linked list
	
	bago->data = nd;
	bago->next = NULL;
	
	if(*head == NULL){
		*head = bago;
		return;
	}
	
	while(last->next != NULL){
		last = last->next; //traverses through to end of list if not empty
	}
	
	last->next = bago; //adds new data to end of list
	return;
}

void insert_after(struct Node* prev, int nd){
	if(prev == NULL){
		printf("Previous node cannot be NULL");
		return;
	}
	
	struct Node* bago = (struct Node*)malloc(sizeof(struct Node));
	bago->data = nd;
	bago->next = prev->next; //new node next link now holds the address of the previous link
	//points to previous node next
	prev->next = bago; //previous next link holds the data of the new struct added
	//new is assigned to previous node next
}

void display(struct Node* ptr){
	while(ptr != NULL){
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
}

void main(){
	struct Node* head = NULL;
	insert_end(&head, 11);
	insert_begin(&head, 20);
	insert_begin(&head, 13);
	insert_end(&head, 44);
	insert_after(head->next, 15);
	
	printf("Elements in Linked List are: \n");
	display(head);
}
