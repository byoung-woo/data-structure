#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OK 1
#define NOTOK 0

struct mystr{
	struct mystr *next, *prev;
	int age;
	char name[52];
	char *message;
};

struct mystr *head = 0;

int add(int age, char *name, char *msg){
	struct mystr *new;

	if((new = malloc(sizeof(struct mystr)))==NULL)
		return (NOTOK);
	new->next = new->prev = 0;
	new->age = age;
	strcpy(new->name, name);
	new->message =malloc(8);
	strcpy(new->message, msg);

	if(!head)
	{
		head=new;
		return (OK);
	}
	
	new->next=head;
	head->prev=new;
	head=new;

	return (OK);
}

void print(void){
	struct mystr *ptr;
	for(ptr=head; ptr; ptr=ptr->next){
		printf("age = [%d]\n", ptr->age);
		printf("name = [%s]\n", ptr->name);
		printf("message = [%s]\n", ptr->message);
	}
}
int main(){
	add(14, "qkr", "ledt");
	print();
}     
