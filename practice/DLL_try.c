#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* prev;
	struct node* next;
};

int main(){
	//declare variables
	struct node* head;
	struct node* first;
	struct node* second;
	struct node* third;
	
	//allocate memory;
	first = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	third = (struct node*)malloc(sizeof(struct node));
	
	//assign data
	first->data = 10;
	second->data = 20;
	third->data = 30;
	
	//connect nodes
	first->prev = NULL;
	first->next = second;
	second->prev = first;
	second->next = third;
	third->prev = second;
	third->next = NULL;
	
	//connect head;
	head = first;
	
	//display forwards
	printf("Displaying forward: ");
	struct node* ptr;
	ptr = head;
	while(ptr!=NULL){
		printf("%d -> ", ptr->data);
		ptr = ptr->next;
	}
	
	//displaying backwards (just trying but i know it doesnt work)
	struct node* backward;
	backward = third;
	printf("\nDisplaying backward: "); 
	while(backward!=NULL){
		printf("%d -> ", backward->data);
		backward = backward->prev;
	}
	
	return 0;
}
