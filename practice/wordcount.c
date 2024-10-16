#include<stdio.h>
#include<string.h>

void wordCount(char string[]){
	int i;
	int count = 0;
	for(i=0; i<100; i++){
		if(string[i] == ' '){
			count++;
		}
	}
	printf("Word count: %d", count);
}

int main(){
	char string[100];
	printf("Enter a string: ");
	gets(string);
	wordCount(string);
}
