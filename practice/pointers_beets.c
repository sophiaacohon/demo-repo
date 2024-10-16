#include<stdio.h>

int compute(int *a, int *b);

void main(){
	int x, y;
	int *a, *b;
	a = &x;
	b = &y;
	printf("Enter a: ");
	scanf("%d", &x);
	printf("Enter b: ");
	scanf("%d", &y);
	compute(a, b);
	printf("Answer is: %d", *a);
}

int compute(int *a, int *b){
	if(*a>*b){
		*a *= *b;
		return *a;
	}
	else if(*a<*b){
		*a += *b;
		return *a;
	}
}

