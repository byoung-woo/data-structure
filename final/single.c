#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OK 1
#define NOTOK 0

struct mystr {
	struct mystr *next;
	int age;
	char name[52];
	char *message;
};
struct mystr *head=0;

int add(int age, char *name, char *msg){
	struct mystr *new, *last;
	if((new=malloc(sizeof(struct mystr)))==NULL)
		return (NOTOK);
	new->next = 0;
	new->age = age;
	strcpy(new->name, name);
	new->message = malloc (8);
	strcpy (new->message, msg);

	if (!head){
		head = new;
		return (OK);
	}
	for(last=head; last->next; last=last->next)
		;
	last->next=new;
	return (OK);
}

int delete(char *name){
	struct mystr *ptr, *prev=0;
	for(ptr=head; ptr; prev=ptr, ptr=ptr->next)
	{	if(!strcmp(name, ptr->name))
		{	if(ptr==head)
				head=ptr->next;
			else
			{	prev->next=ptr->next;
			}
			free(ptr->message);
			free(ptr);
			return(OK);
		}
	}
	return(NOTOK);	
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
	add(23, "Hong", "hello");
	add(28, "kim", "test");
	print();

	delete("cho");
	delete("lee");
	print();
}
