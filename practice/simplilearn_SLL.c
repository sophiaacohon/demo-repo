#include <stdio.h>
#include <stdlib.h>

void display();

struct Node{
	int data;
	struct Node* next;
};

int main(){
	//step 1: declare pointers
	struct Node* first;
	struct Node* second;
	struct Node* third;
	struct Node* fourth;
	
	//step 2: allocate dynamic memory
	first = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));
	fourth = (struct Node*)malloc(sizeof(struct Node));
	
	//step 3: assign data
	first->data = 10;
	second->data = 20;
	third->data = 30;
	fourth->data = 40;
	
	//step 4: link to next node
	first->next = second;
	second->next = third;
	third->next = fourth;
	fourth->next = NULL;
	
	//display nodes in linked list, first pointer is pass by reference
	display(first);
	return 0;
}

void display(struct Node* ptr){
	printf("Elements in Linked List are: \n");
	while(ptr != NULL){
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
}
