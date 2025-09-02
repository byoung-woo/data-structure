#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OK 1
#define NOTOK 0

struct mystr {
	struct mystr *next, *prev;
	int age;
	char name[8];
	char *message;
};

struct mystr *head = 0;

int add(int age, char *name, char *msg){
	struct mystr *new, *last;
	if((new=malloc(sizeof(struct mystr)))==NULL)
		return (NOTOK);
	
	new->next = new->prev = 0;
	new->age = age;
	strcpy(new->name, name);
	new->message = malloc(8);
	strcpy(new->message, msg);

	if(!head){
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
			return (OK);	
		}		
	}
 return(NOTOK);
}

void print(void){
	struct mystr *ptr=head;

	printf("출력-------------------\n");
	while(ptr){
	printf("\t\tage = [%d], name = [%s], message = [%s]\n", ptr->age, ptr->name, ptr->message);
	ptr=ptr->next;
}
}

int main(){
	int age;
	char name[8], message[8], command[8];

	printf("커맨드 입력. (add, delete, print, end) ");
	scanf("%s", command);

 while(strcmp(command, "end")){
        if(!strcmp(command, "add")){
            printf("\t입력하세요  나이, 이름, 메세지 ");
            scanf("%d %s %s", &age, name, message);
            if(add(age, name, message)==OK)
                printf("\t\tadded successfully.\n");
            else
                printf("\t\tadd fail.\n");
        }
        else if(!strcmp(command, "delete")){
            printf("\t 이름을 입력하시오 ");
            scanf("%s", name);
            if(delete(name)==OK)
                printf("\t\tdeleted successfully.\n");
            else
                printf("\t\tdeleted fail.\n");
        }
        else if(!strcmp(command, "print")){
            print();
        }
        else if(!strcmp(command, "end")){
            printf("\tend\n");
            exit (1);
        }
		else
			printf("unknown command\n");
		printf("커맨드 입력. (add, delete, print, end) ");
	    scanf("%s", command);

    }
}

