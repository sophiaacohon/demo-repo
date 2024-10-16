/*
Attempting first to make a program that can perform CRUD oeprations on arrays before doing it on cursor based
The program can Add, Edit, Delete, Search, and Show Elements of an Array
Created by: Sophia Cohon
February 19, 2023, Sunday
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

int array[100];
int index = 0;

void add(int array[100], int n){
	if(index>99){
		printf("Array is full!");
	}
	else{
		array[index] = n;
		index++;
	}
	
}

void edit(int array[100], int pos, int n){
	int i;
	for(i=0; i<100; i++){
		if(i == pos){
			array[i] = n;
		}
	}
}

void delEl(int array[100], int pos){
	/*
	1. select position of element to be edited
	2. once the position is inputted, the rest of the elements shift to the left.
	ex:
	1 2 3 4 5 6 7 8 9 10
	delete element at position 3
	1 2 3 5 6 7 8 9	
	*/
	
	int i;
	if(pos<0 || pos>99){
		printf("\nInvalid Size!\n");
	}
	else{
		for(i=pos; i<100; i++){
			array[i] = array[i+1];
		}
	}
}

void main(){
	int choice;
	int i, posN, addN, editN, posD, posS;
	do{
		system("cls");
		printf("\nMENU: \n");
		printf("1. Add Element\n");
		printf("2. Edit Element\n");
		printf("3. Delete Element\n");
		printf("4. Search Element\n");
		printf("5. Show Elements\n");
		printf("0. EXIT\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("\nAdd Element to Array\n");
				printf("Enter a number: ");
				scanf("%d", &addN);
				add(array, addN);
				break;
			case 2:
				printf("\nEdit Element in Array\n");
				for(i=0; i<100; i++){
					if(array[i]==0){
						break;
					}
					printf("Index [%d]: %d\n", i, array[i]);
				}
				printf("Enter the position of element to be edited: ");
				scanf("%d", &posN);
				printf("Enter a number: ");
				scanf("%d", &editN);
				edit(array, posN, editN);
				break;
			case 3:
				printf("\nDelete Element in Array\n");
				printf("Enter the position of element to be deleted: ");
				scanf("%d", &posD);
				delEl(array, posD);
				printf("Element in positioned in index [%d] was successfully deleted.\nPress Enter to continue\n", posD);
				getch();
				break;
			case 4:
				printf("\nSearch Element in Array\n");
				printf("Enter the position of element to be searched: ");
				scanf("%d", &posS);
				for(i=0; i<100; i++){
					if(posS == i){
						printf("Element in index [%d] is %d\n", posS, array[i]);
					}
				}
				printf("Press Enter to continue\n");
				getch();
				break;
			case 5:
				printf("\nShow Elements in Array\n");
				for(i=0; i<100; i++){
					if(array[i]==0){
						break;
					}
					printf("Index [%d]: %d\n", i, array[i]);
				}
				printf("Press Enter to continue\n");
				getch();
				break;
		}
	}while(choice!=0);
	printf("\n\nProgram Terminated. Thank you!");
}
