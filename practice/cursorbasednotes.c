/*
cursor based
a combination of array and linked list
uses array data structure
linked/controlled as a linked list
a continuous memory allocation
is created in the stack
called virtual heap because it is a mix of array and linked list
-1 means end or NULL
must have variable avail for next available index for borrowing memory
no malloc calloc free in cursor based

*/

#include<stdio.h>
#define SIZE 5
/*
typedef struct{
	int elem;
	int next;
}ArrData;

typedef struct{
	ArrData data[SIZE];
	int avail;
}Space, VSpace;

int allocSpace(VSpace *vs){
	//request space
	int index = vs->avail;
	if(index!=-1){
		vs->avail = vs->data[index].next;
		//if your index is not -1
	}
	return index;
	//returns -1 if there is no more space to be allocated
}

void main(){
	VSpace s;
	s.data[3].elem; //is this even right?
}
*/
typedef struct{
	int elem;
	int next;
}Space;

typedef struct{
	Space data[20];
	int avail;
}VSpace;

int allocSpace(VSpace *vs){
	//request space
	int index = vs->avail;
	if(index!=-1){
		vs->avail = vs->data[index].next;
		//if your index is not -1
	}
	return index;
	//returns -1 if there is no more space to be allocated
}

