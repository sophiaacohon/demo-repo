/*
Attempting to make a program that can Add, Show, and Delete Elements 
in an array using Cursor Based Implementation
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

struct elem{
	int data;
	int next;
};

struct CB{
	struct elem info[100];
	int start;
	int available;
};

/*
PSEUDOCODE

ADD:
start = 0
index = 0
myCB.info[index].data = num
myCB.info[index].next = -1
for(index=0; index<100; index++){
	if(myCB.info[index].data == 0){
		myCB.available = index
		break
	}
}

DELETE:
enter position to delete: int posD









*/


void main(){
	int choice;
	int addN, delN;
	do{
		system("cls");
		printf("\nMENU: \n");
		printf("1. Add Element\n");
		printf("2. Delete Element\n");
		printf("3. Show Elements based on index\n");
		printf("4. Show Elements based on next link\n");
		printf("0. EXIT\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("\nAdd Element\n");
				printf("Enter a number: ");
				scanf("%d", &addN);
				//add function??
				break;
			case 2:
				printf("\nDelete Element\n");
				printf("Enter a position: ");
				scanf("%d", &delN);
				//delete function??
				break;
			case 3:
				printf("\nShow Elements based on index\n");
				//elements shown must be based on the index
				break;
			case 4:
				printf("\nShow Elements based on next link\n");
				//elements shown must be based on the next link
		}
	}while(choice!=0);
}
