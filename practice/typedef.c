#include<stdio.h>

int main(){
	int i;
	typedef int Dictionary;
	Dictionary D[10];
	for(i=0; i<10; i++){
		printf("Enter number: ");
		scanf("%d", &D[i]);
	}
	
	for(i=0; i<10; i++){
		printf("%d\n", D[i]);
	}
	return 0;
}
