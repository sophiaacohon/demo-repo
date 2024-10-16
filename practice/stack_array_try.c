/*
attempting to make my own array implementation of stack based on what ive learned from neso
by: Sophia Cohon
March 20, 2023
*/

#include<stdio.h>
#define SIZE 5
int stack_arr[SIZE];
int top = -1;

void push(int n){
	if(top >= SIZE-1){
		printf("Stack Overflow\n");
	}
	else{
		top++;
		stack_arr[top] = n;
		//printf("Top value: %d\n", top);
	}
}

int pop(){
	if(top == -1){
		printf("Stack Underflow\n");
	}
	else{
		stack_arr[top] = 0;
		top--;
	}
	/*
	NESO STYLE:
	int value;
	if(top == -1){
		printf("Stack Underflow\n");
		exit(1);
	}
	value = stack_arr[top];
	top = top-1;
	return value;
	*/
	
}

void main(){
	int choice, n, i;
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
				printf("Stack:\n");
				for(i=top; i>=0; i--){
					printf("%d\n", stack_arr[i]);
				}
				break;
		}
	}while(choice!=0);
	
}
