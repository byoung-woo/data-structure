#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OK 1
#define NOTOK 0

struct mystr {
	struct mystr *next, *prev;
	int age;
	char name[52];
	char *message;
};
struct mystr *head=0;

int add(int age, char *name, char *msg){
	struct mystr *new, *last;
	if((new=malloc(sizeof(struct mystr)))==NULL)
		return (NOTOK);
	new->next = new->prev = 0;
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
	new->prev=last;
	return (OK);
}

int delete(char *name){
	struct mystr *ptr;
	for(ptr=head; ptr; ptr=ptr->next)
	{	if(!strcmp(name, ptr->name))
		{	if(ptr->prev==0)
			{	head=ptr->next;
				if(head)
				head->prev=0;
			}
			else
			{	ptr->prev->next=ptr->next;
				if(ptr->next)
					ptr->next->prev=ptr->prev;
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

	if(delete("Hong")==OK)
		printf("Hong : deleted\n");
	print();

	add(21, "park", "hi");
    add(22, "lee", "champios");
    print();

	delete("cho");
	print();
	
	delete("lee");
	print();
}
