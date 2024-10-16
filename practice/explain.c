#include<stdio.h>
void main(){
	int x, y, sum=0;
	printf("Enter a value for x: ");
	scanf("%d", &x);
	printf("Enter a value for y: ");
	scanf("%d", &y);
	sum = x+y;
	printf("The sum of x and y are: %d", sum);
	sum = x-y;
	printf("The difference of x and y are: %d", sum);
}
