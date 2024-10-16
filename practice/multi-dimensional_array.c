#include<stdio.h>

int main(){
	int mat[3][3] = {{12, 8, 2}, {17, 19, 5}, {6, 11, 2}};
	
	printf("%d", sizeof(mat[0])/sizeof(int));
	
	return 0;
}
