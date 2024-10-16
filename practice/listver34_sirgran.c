//list implementation version 3
//a structure containing a pointer to an array,
//a count and max variable

#include <stdio.h>
#include<stdlib.h>
typedef struct{
	int *arr;
	int count;
	int max;
}ArrayList;

void initAL(ArrayList *list, int n){
	list->arr = (int*)malloc(sizeof(int)*n); //allocate memory in the heap
	//woohoo meron parin akong utak haha
	list->count = 0; //initialize
	list->max = n;
	//creates empty representation of list
}

ArrayList newAL (int n){
	//creates ArrayList with return statement
	ArrayList list;
	list.arr = (int*)malloc(sizeof(int)*n);
	list.count = 0;
	list.max = n;
	return list;
}

void main(){
	ArrayList myList = newAL(10);
	ArrayList list2;
	initAL(&list2, 5);
}
