#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10


typedef struct{
	char name[MAX_NAME];
	int age;
}person;

#define DELETED_NODE (person*)(0xFFFFFFFFFFFFFFFFUL)

person *hash_table[MAX_NAME];

unsigned int hash(char *name){
	int i;
	int length = strnlen(name, MAX_NAME);
	unsigned int hash_value = 0;
	for(i=0; i<length; i++){
		hash_value += name[i];
		hash_value = (hash_value * name[i]) % TABLE_SIZE;
	}
	return hash_value;
}

void init_hash_table(){
	int i;
	for(i=0; i<TABLE_SIZE; i++){
		hash_table[i] = NULL;
	}
}

void print_table(){
	printf("Start\n");
	int i;
	for(i=0; i<TABLE_SIZE; i++){
		if(hash_table[i] == NULL){
			printf("\t%i\t----\n", i);
		}
		else if (hash_table[i] == DELETED_NODE){
			printf("\t%i\t----<deleted>\n", i);
		}
		else{
			printf("\t%i\t%s\n", i, hash_table[i]->name);
		}
	}
	printf("End\n");
}

bool hash_table_insert(person *p){
	int i;
	if(p==NULL){
		return false;
	}
	int index = hash(p->name);
	for(i=0; i<TABLE_SIZE; i++){
		int geh = (i+index)% TABLE_SIZE;
		if(hash_table[geh] == NULL || 
		hash_table[geh == DELETED_NODE]){
			hash_table[geh] = p;
			return true;
		}
	}
	return false;
}

person *hash_table_lookup(char *name){
	int i;
	int index = hash(name);
	for(i=0; i<TABLE_SIZE; i++){
		int geh = (i+index)% TABLE_SIZE;
		if(hash_table[geh] == NULL){
			return false;
		}
		if(hash_table[geh] == DELETED_NODE){
			continue;
		}
		if(hash_table[geh]!=NULL && 
		strncmp(hash_table[geh]->name, name, TABLE_SIZE)==0){
			return hash_table[geh];
		}
	}
	return NULL;
}

person *hash_table_delete(char *name){
	int i;
	int index = hash(name);
	for(i=0; i<TABLE_SIZE; i++){
		int geh = (i+index)% TABLE_SIZE;
		if(hash_table[geh] == NULL){
			return NULL;
		}
		if(hash_table[geh] == DELETED_NODE){
			continue;
		}
		if(strncmp(hash_table[geh]->name, name, TABLE_SIZE)==0){
			person *tmp = hash_table[geh];
			hash_table[geh] = DELETED_NODE;
			return tmp;
		}
	}
	return NULL;
}

int main(){
	init_hash_table();
	print_table();
	
	person jacob = {.name="Jacob", .age=256};
	person kate = {.name="Kate", .age=27};
	person mpho = {.name="Mpho", .age=14};
	person sarah = {.name="Sarah", .age=14};
	person edna = {.name="Edna", .age=54};
	person maren = {.name="Maren", .age=15};
	person eliza = {.name="Eliza", .age=25};
	person robert = {.name="Robert", .age=31};
	person jane = {.name="Jane", .age=1};
	person sophia = {.name="Sophia", .age=20};
	
	hash_table_insert(&jacob);
	hash_table_insert(&kate);
	hash_table_insert(&mpho);
	hash_table_insert(&sarah);
	hash_table_insert(&edna);
	hash_table_insert(&maren);
	hash_table_insert(&eliza);
	hash_table_insert(&robert);
	hash_table_insert(&jane);
	hash_table_insert(&sophia);
	print_table();
	
	person *tmp = hash_table_lookup("Mpho");
	if(tmp==NULL){
		printf("Not Found.\n");
	}
	else{
		printf("Found %s.\n", tmp->name);
	}
	
	tmp = hash_table_lookup("George");
	if(tmp==NULL){
		printf("Not Found.\n");
	}
	else{
		printf("Found %s.\n", tmp->name);
	}
	
	hash_table_delete("Mpho");
	tmp = hash_table_lookup("Mpho");
	if(tmp==NULL){
		printf("Not Found.\n");
	}
	else{
		printf("Found %s.\n", tmp->name);
	}
	
	print_table();
	
	/*
	printf("Jacob => %u\n", hash("Jacob"));
	printf("Natalie => %u\n", hash("Natalie"));
	printf("Sara => %u\n", hash("Sara"));
	printf("Mpho => %u\n", hash("Mpho"));
	printf("Tebogo => %u\n", hash("Tebogo"));
	printf("Ron => %u\n", hash("Ron"));
	printf("Jane => %u\n", hash("Jane"));
	printf("Sophia => %u\n", hash("Sophia"));
	printf("Maren => %u\n", hash("Maren"));
	printf("Bill => %u\n", hash("Bill"));
	*/
	return 0;
}
