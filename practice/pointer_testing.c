#include <stdio.h>

int main(){
	int num = 8; //holds an integer
	int* s = &num; //holds the address of an itneger
	int** d = &s; //holds the address of a pointer
	printf("num: %d", num); //output: 8
	printf("\nvalue of d: %d", *s); //output: 8
	printf("\nd: %d", **d); //output :8
	printf("\n");
	printf("\ns: %p", s); //output: address of s
	printf("\naddress stored in d: %p", *d); //output: address of s
	
	
	
	return 0;
}
