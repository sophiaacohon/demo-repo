#ifndef MYHEADER_H
#define MYHEADER_H
#include<stdio.h>

#define MAX 10
#define TRUE 1
#define FALSE 0

typedef int Boolean;
typedef int Location;
typedef int List; //the same as starting point, just a list

typedef struct{
	int elem; //data compartment
	Location next;
} Space[MAX];

typedef struct{
	Space data;
	Location avail;
} VSpace;

void initVSpace(VSpace *vs){
	//parameter is a pointer because data is changed in function
	int i;
	for(i=MAX-1; i>=0; --i){
		vs->data[i].next = i-1;
	}
	vs->avail = MAX-1;
}

int allocSpace(VSpace *vs){
	int index = vs->avail;
	if(index != -1){
		vs->avail = vs->data[index].next;
	}
	return index;
}

Boolean insertFront(VSpace *vs, List *l, int item){
	Location temp = allocSpace(vs);
	if(temp != -1){
		vs->data[temp].elem = item;
		vs->data[temp].next = *l;
		*l = temp;
		return TRUE;
	}
	return FALSE;
}

void displayList(VSpace vs, List l){
	int i=l;
	printf("{");
	
	while(i != -1){
		printf("%d ", vs.data[i].elem);
		i = vs.data[i].next;
	}	
	printf("}\n");
}

void visualizeVSpace(VSpace vs){
	//no need pointer
	//retrieve and see whats inside vs
	int i;
	printf("%8s | %8s | %8s\n", "INDEX", "ELEM", "NEXT");
	for(i=0; i<MAX; ++i){
		printf("%8d | %8d | %8d\n", i, vs.data[i].elem, vs.data[i].next);
	}
	printf("AVAILABLE: %d\n\n", vs.avail);
}

#endif
