/*
An attempt to try to do on my own the linked list operations
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

void create(int num){
	int i, n;
	struct node *ptr, *temp;
	printf("Enter data for node 1: ");
	scanf("%d", &n);
	head = (struct node*)malloc(sizeof(struct node));
	head->data = n;
	head->next = NULL;
	ptr = head;
	for(i=2; i<=num; i++){
		temp = (struct node*)malloc(sizeof(struct node));
		if(temp == NULL){
			printf("Memory Not Allocated");
			break;
		}
		else{
			printf("Enter data for node %d: ", i);
			scanf("%d", &n);
			temp->data = n;
			temp->next = NULL;
			ptr->next = temp;
			ptr = temp;
		}		
	}
}

void insert_begin(int n){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = n;
	temp->next = NULL;
	if(head == NULL){
		head = temp;
		return;
	}
	else{
		temp->next = head;
		head = temp;
	}
	
}

void insert_pos(int pos, int n){
	int i;
	struct node* temp;
	struct node* ptr;
	struct node* prev_ptr;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = n;
	temp->next = NULL;
	ptr = head;
	if(head == NULL){
		head = temp;
		return;
	}
	else{
		for(i=0; i<pos; i++){
			prev_ptr = ptr;
			ptr = ptr->next;
		}
		temp->next = ptr;
		prev_ptr->next = temp;
	}
}

void insert_end(int n){
	struct node* temp;
	struct node* ptr;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = n;
	temp->next = NULL;
	ptr = head;
	if(head == NULL){
		head = temp;
		return;
	}
	else{
		//struct node* ptr = head;
		while(ptr->next!=NULL){
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
}

void del_begin(){
	struct node* temp;
	struct node* ptr;
	temp = head;
	ptr = head;
	if(head == NULL){
		printf("Linked List is empty, Nothing to delete.");
		return;
	}
	else{
		ptr = head->next;
		head = ptr;
		free(temp);
		printf("\nNode at Beginning is successfully deleted.\n");
	}
}

void del_pos(int pos){
	int i;
	struct node* prev_ptr = NULL;
	struct node* ptr = head;
	if(head == NULL){
		printf("Linked List is empty, Nothing to delete.");
		return;
	}
	else if(pos == 0){
		head = ptr->next
		free(ptr);
	}
	else{
		for(i=0; i<pos; i++){
			prev_ptr = ptr;
			ptr = ptr->next;
		}
		prev_ptr->next = ptr->next;
		free(ptr);
		printf("\nNode at Position %d is successfully deleted.\n", pos);
	}
}


void del_end(){
	struct node* ptr = head;
	struct node* prev_ptr = NULL;
	if(head == NULL){
		printf("Linked List is empty, Nothing to delete.");
		return;
	}
	else if(head->next == NULL){
		head = ptr->next;
		free(ptr);
	}
	else{
		while(ptr->next !=NULL){
			prev_ptr = ptr;
			ptr = ptr->next;
		}
		prev_ptr->next = NULL;
		free(ptr);
		printf("\nNode at End is successfully deleted.\n");
	}
}

void display(){
	if(head == NULL){
		printf("Linked List is empty.\n");
		return;
	}
	struct node *ptr = head;
	while(ptr!=NULL){
		printf("%d -> ", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL");
}

void main(){
	int choice;
	int num, n, pos;
	do{
		printf("\n1. Create");
		printf("\n2. Insert at Beginning");
		printf("\n3. Insert at Position");
		printf("\n4. Insert at End");
		printf("\n5. Delete at Beginning");
		printf("\n6. Delete at Position");
		printf("\n7. Delete at End");
		printf("\n8. Display");
		printf("\n0. EXIT");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("\nCreate a Linked List\n");
				printf("Enter number of nodes: ");
				scanf("%d", &num);
				create(num);
				break;
			case 2:
				printf("\nInsert node at Beginning of Linked List\n");
				printf("Enter a number: ");
				scanf("%d", &n);
				insert_begin(n);
				break;
			case 3:
				printf("Insert node at a Position of Linked List");
				printf("Enter Position: ");
				scanf("%d", &pos);
				printf("Enter a number: ");
				scanf("%d", &n);
				insert_pos(pos, n);
				break;
			case 4:
				printf("\nInsert node at End of Linked List\n");
				printf("Enter a number: ");
				scanf("%d", &n);
				insert_end(n);
				break;
			case 5: 
				printf("\nDelete Node at Beginning of the Linked List\n");
				del_begin();
				break;
			case 6:
				printf("\nDelete Node at a Position of the Linked List\n");
				printf("Enter Position");
				scanf("%d", &pos);
				del_pos(pos);
				break;
			case 7: 
				printf("\nDelete node at End of Linked List\n");
				del_end();
				break;
			case 8:
				printf("\nDisplay Linked List\n");
				display();
				break;
		}
	}while(choice!=0);
	printf("\nPROGRAM TERMINATED...");
}
