#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

struct Node *head;

void create(int num){
	int i, n;
	struct Node *ptr, *temp;
	head = (struct Node*)malloc(sizeof(struct Node));
	printf("Enter value for node 1: ");
	scanf("%d", &n);
	head->data = n;
	head->next = NULL;
	ptr = head;
	for(i=2; i<=num; i++){
		temp = (struct Node*)malloc(sizeof(struct Node));
		if(temp == NULL){
			printf("Memory not allocated");
			break;
		}
		else{
			printf("Enter value for node %d: ", i);
			scanf("%d", &n);
			temp->data = n;
			temp->next = NULL;
			ptr->next = temp;
			ptr = ptr->next;
		}
		
	}
}

void display(){
	struct Node *ptr;
	ptr = head;
	if(head == NULL){
		printf("Linked List is empty.");
	}
	while(ptr != NULL){
		printf("%d\t", ptr->data);
		ptr = ptr->next;
	}
}

void main(){
	int num;
	printf("Enter number of nodes: ");
	scanf("%d", &num);
	create(num);
	display();
}
