#include <stdio.h>
#include <string.h>

void nums(int n){
	static int n1=0, n2=1, n3;
	if(n>0){
		n3 = n2 + n1;
		n1 = n2;
		n2 = n3;
		printf("%d ", n3);
		nums(n-1);
	}
	
}

void main(){
	int n;
	printf("Input number of terms for the series(<20): ");
	scanf("%d", &n);
	
	printf("The series are: ");
	printf("%d %d ", 0, 1);
	nums(n-2);
	
}

/*
int nums(int n){
	if(n==1){
		return 1;
	}
	else{
		return n + nums(n-1);
	}
}

void main(){
	int n;
	printf("Input the last number of the range starting from 1: ");
	scanf("%d", &n);
	int sum = nums(n);
	printf("The sum of numbers from 1 to %d is %d", n, sum);
}
*/

/*
int nums(int n){
	if(n<=50){
		printf("%d ", n);
		nums(n+1);
	}
}

void main(){
	int n = 1;
	nums(n);
}
*/

/*
int palindrome(char s[]){
	int i = 0, c = 0;
	int n = strlen(s);
	if(i<n/2){
		if(s[i]==s[i-n-1]){
			c++;
			i++;
			palindrome(s);
		}
	}
	else{
		if(c==i){
			return 1;
		}
		else{
			return 0;
		}
	}
}

int main(){
	char s[100];
	printf("Enter a string: ");
	gets(s);
	if(palindrome(s)){
		printf("This string is a palindrome");
	}
	else{
		printf("This string is not a palindrome");
	}
	return 0;
}
*/

/*
int smallest(int array[], int length){
	if(length == 1){
		return array[length-1];
	}
	int possible = smallest(array, length-1);
	if(possible < array[length-1]){
		return possible;
	}
	else{
		return array[length-1];
	}
	
}

int main(){
	int array[] = {87, 43, 36, 52, 9, 65, 74, 22};
	int length = 8;
	int min = smallest(array, length);
	printf("Minimum number in array is %d\n", min);
	return 0;
}
*/

/*
this does not work
int smallest(int array[], int index, int length){
	//int i;
	int min = array[0];
	if(index < length){
		if(array[index]<min){
			min = array[index];
		}
		smallest(array, index+1, length);
	}
	return min;
	
}

int main(){
	int array[] = {87, 43, 36, 52, 9, 65, 74, 22};
	int length = 8;
	int min = smallest(array, 0, length);
	printf("Minimum number in array is %d\n", min);
	return 0;
}
*/

/*
int main(){
	int array[] = {87, 43, 36, 52, 9, 65, 74, 22};
	int length = 8;
	int i;
	int min = array[0];
	for(i=0; i<length; i++){
		if(array[i]<min){
			min = array[i];	
		}
	}
	printf("Minimum number in array is %d", min);
	return 0;
}
*/

/*
int reverse(int array[], int low, int high){
	if(low<high){
		int temp = array[low];
		array[low] = array[high];
		array[high] = temp;
		reverse(array, low+1, high-1);
	}
	
}

int main(){
	int i;
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int length = 8;
	reverse(array, 0, length-1);
	for(i=0; i<length; i++){
		printf("[%d] ", array[i]);
	}
	return 0;
}
*/

/*
int array[] = {1, 2, 3, 4, 5, 6, 7, 8};

int reverse(int length){
	if(length == -1){
		return 1;
	}
	else{
		printf("[%d] ", array[length]);
		return 1 + reverse(length-1);
	}
}

int main(){
	int len = 8;
	int length  = len - 1;
	reverse(length);
	return 0;
}
*/

/*
int factorial(int n){
	if(n==1){
		return 1;
	}
	else{
		return n * factorial(n-1);
	}
	
}

int main(void){
	int n=0;
	int fact;
	printf("Enter a number: ");
	scanf("%d", &n);
	fact = factorial(n);
	printf("factorial: %d", fact);
	return 0;
}
*/

/*
int main(void){
	int n=0;
	int fact = 1;
	printf("Enter a number: ");
	scanf("%d", &n);
	while(n>=1){
		fact = n*fact;
		n--;
	}
	printf("factorial: %d", fact);
}
*/

/*
//problem: calculate factorial of the number
//source: Neso Academy
int fact(int n){
	if(n==1){
		return 1;
	}
	else{
		return n*fact(n-1);
	}
}

int main(){
	int n;
	printf("Enter n: ");
	scanf("%d", &n);
	printf("The factorial of %d is %d", n, fact(n));
}
*/


/*
fact(){
	if(){
		//base case
		//doesnt require the same function again
		//helps in stopping the recursion
	}
	else{
		//recursive procedure
	}
}
*/

/*
int fun(int n){
	if(n==0){
		return 1;
	}
	else{
		return 7 + fun(n-2);
	}
}

int main(){
	printf("%d", fun(4));
	//output is 15
	return 0;
}

fun(4) -> 7+7+1 = 15
return 7 + fun(2) -> 7
return 7 + fun (0) -> 7
return 1 => go back to caller function
*/

