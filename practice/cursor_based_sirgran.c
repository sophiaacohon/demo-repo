#include<stdio.h>
#include<stdlib.h>
#include"myheader.h"

int main(int argc, char *argv[]){
	VSpace mySpace;
	List myList = -1;
	initVSpace(&mySpace);
	visualizeVSpace(mySpace);
	
	insertFront(&mySpace, &myList, 10);
	displayList(mySpace, myList);
	insertFront(&mySpace, &myList, 5);
	displayList(mySpace, myList);
	visualizeVSpace(mySpace);
}
