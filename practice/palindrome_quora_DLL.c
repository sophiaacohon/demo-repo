#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{

int data;

struct node *next;

struct node *prev;

};

//suppose we have head

bool pallin(struct node *head){

struct node * t = head;

while(t->next != NULL){

t = t->next;

}

struct node * p1 = head;

struct node * p2 = t;

while(p1->next != p2 || p1 != p2){

if(p1->data != p2->data){

return false;

}

p1 = p1->next;

p2 = p2->prev;

}

return true;

}
