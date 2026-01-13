#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OK 1
#define NOTOK 0

struct node {
	struct node *next, *prev;
	char name[52];
	char number[30];
} *head;

int insert(char *name, char *number){
	struct node *new, *last;
	if((new=malloc(sizeof(struct node)))==NULL)
		return (NOTOK);
	new->next = new->prev = 0;
	strcpy(new->name, name);
	strcpy (new->number, number);

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

int find(char *name){
	struct node *ptr;
	int found = 0;
	for(ptr=head; ptr; ptr=ptr->next){
		if(!strcmp(name, ptr->name)){
			printf("%s :  %s\n", ptr->name, ptr->number);
			found = 1;
		}
	}
		if(!found)
			printf("not find\n");
}
void print(void){
	struct node *ptr;
	for(ptr=head; ptr; ptr=ptr->next){
		printf("name = [%s]\n", ptr->name);
		printf("number = [%s]\n\n", ptr->number);
	}	
}

int delete(char*name){
	struct node *ptr;
	for (ptr = head; ptr; ptr = ptr->next) {
		if(!strcmp(name, ptr->name)){
			if(!(ptr->prev)){
				head=ptr->next;
				if(head)
				head->prev=0;
			}
			else{
				ptr->prev->next=ptr->next;
				if(ptr->next)
					ptr->next->prev=ptr->prev;
			}
		free(ptr);
		printf("========delete node=======\n");
		return OK;
		}
	}
}
int main(){
	char name[52], number[52], command[10];

	printf("input command : insert, print, find, quit :");
	scanf("%s", command);

	while(strcmp(command, "quit")){
		if(!strcmp(command, "insert")){
			printf("name ?\n");
			scanf("%s", name);
			printf("number ?\n");
			scanf("%s", number);
			insert(name, number);
		}
		else if(!strcmp(command, "find")){
		    printf("name ?\n");
            scanf("%s", name);
			find(name);
		}
		else if(!strcmp(command, "print")){
			print();
		}
		else if(!strcmp(command, "quit")){
			exit(1);
		}
		else{
			printf("unknown command.\n");
		}
		printf("input command : insert, print, find, quit :");
	    scanf("%s", command);
	}

}
