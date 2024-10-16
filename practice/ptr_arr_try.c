#include<stdio.h>
int arr[10]={1,1,1,1,1,1,1,1,1,1};

void terminate(int* arr, int x){
	int i;
	int* ptr = arr;
	ptr[x] = 0;
	for(i=0; i<10; i++){
		printf("%d ", ptr[i]);
	}
}

int main(void){
	int x;
	printf("Enter a number: ");
	scanf("%d", &x);
	terminate(arr, x);
	return 0;
}
