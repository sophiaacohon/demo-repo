#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head;

void createnodes(int n){
	struct node *newNode;
	struct node *ptr;
	int nodeData, nodeCounter;
	
	//allocate memory for starting node:
	head = (struct node*)malloc(sizeof(struct node));
	
	printf("input data for node1: ");
    scanf("%d", &nodeData);

    //save user input to the data element of the node
    head->data = nodeData;
    //initialize the nodes next pointer to null
    head->next = NULL;
    //Point the buffer to address of the first node
    ptr = head;
    
    for(nodeCounter=2; nodeCounter<=n; nodeCounter++){
    	newNode = (struct node*)malloc(sizeof(struct node));
    	
    	if(newNode == NULL){
    		printf("Memory cannot be allocated");
    		break;
		}
		else{
			printf("Input data for node %d: ", nodeCounter);
			scanf("%d", &nodeData);
			newNode->data = nodeData;
			newNode->next = NULL;
			
			ptr->next = newNode;
			ptr = ptr->next;
		}
	}
}

void display(){
	struct node *ptr;
	ptr = head;
	if(ptr == NULL){
		printf("Linked list is empty");
		return 0;
	}
	else{
		while(ptr !=NULL){
			printf("%d\t", ptr->data);
			ptr = ptr->next;
		}
	}
}

void main(){
	int num;
	
	printf("Input number of nodes: ");
	scanf("%d", &num);
	createnodes(num);
	display();
	return 0;
}

/*

	//1. initialize nodes
	struct node *head;
	struct node *one;
	struct node *two;
	struct node *three;
	
	//2. Allocate memory
	one = (struct node*)malloc(sizeof(struct node));
	two = (struct node*)malloc(sizeof(struct node));
	three = (struct node*)malloc(sizeof(struct node));
	
	//3. assign data
	one->data = 1;
	two->data = 2;
	three->data = 3;
	
	//4. connect nodes
	one->next = two;
	two->next = three;
	three->next = NULL;
	
	//5. connect the head
	head = one;
	
	//print
	struct node *ptr = head;
	while(ptr!=NULL){
		printf("%d\t", ptr->data);
		ptr = ptr->next;
	}

*/


/*
typedef struct Node{
	int x;
	struct Node* next;
}Node;


int main(){
	Node root;
	root.x = 15;
	root.next = malloc(sizeof(Node));
	root.next->x = -2;
	root.next->next = NULL;
	
	printf("First: %d\n", root.x);
	printf("Second: %d\n", root.next->x);
	
	free(root.next);
	return 0;
}
*/
