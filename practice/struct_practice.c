#include<stdio.h>
#include<string.h>

struct Student{
	char name[50];
	char section;
	int group;
};

//pass by value
void printStudent(struct Student var){
	printf("Student name: %s\n", var.name);
	printf("Student section: %c\n", var.section);
	printf("Student class: %d\n", var.group);
}

//pass by reference
void changeStudent(struct Student* var){
	var->group = 6;
	var->section= 'b';
}

int main(){
	struct Student student1 = {"student_name", 'A', 5};
	
	//pass by value:
	printStudent(student1);
	
	//pass by reference:
	changeStudent(&student1);
	
	printf("\nAfter passing through changeStudent function woth pass by reference: \n");
	printStudent(student1);
	return 0;
}
