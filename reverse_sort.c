#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define NOTOK 0
#define MSG_SIZE 128

struct mystr{
	struct mystr *next, *prev;
	int age;
	char name[52];
	char *message;
};

int add(int age, char *name, char *msg);
int delete(char *name);
void print(void);
int reverse(void);

struct mystr *head=0;

int main(){
	int age;
	char name[10], message[10], command[10];
	
	while(1){
		printf("input command.(add, delete, reverse, print, end) : ");
		scanf("%s",command);
		
		if(!strcmp(command, "add")){
			printf("\tinpt name, message, age : ");
			scanf("%s %s %d", name, message, &age);
			if(add(age, name, message)==OK) 	printf("\t\tadded successfully.\n");
			else 								printf("\t\tadd fail.\n");
		}
		else if(!strcmp(command, "delete")){
			printf("\tinput name : ");
			scanf("%s",name);
			if(delete(name)==OK)				printf("\t\tdeleted successfully.\n");
			else								printf("\t\tdelete fail.\n");
		}
		 else if(!strcmp(command, "reverse")){
       		reverse();
		 }
		else if(!strcmp(command, "print")){
			print();
		}
		else if(!strcmp(command, "end")){
			printf("\tend\n");
			exit(1);
		}
		else{
			printf("unknow command.\n");
		}
	}
}

int add(int age, char *name, char *msg){
	struct mystr *new, *last;

	if((new=malloc(sizeof(struct mystr)))== NULL){
		return NOTOK;
	}
	
	new->age = age;
	strcpy(new->name, name);
	new->message = malloc(MSG_SIZE);
	strcpy(new->message, msg);
	new->next = new->prev= 0;

	if(head == NULL){
		head = new;
		return OK;
	}
	for(last=head; last->next; last=last->next){
		;
		last ->next = new;
		new->prev = last;
	}
	return OK;
}

int delete(char *name){
	struct mystr *ptr;

	for(ptr=head; ptr; ptr=ptr->next){
		if(!strcmp(name, ptr->name)){
			if(ptr->prev==0){	
				head= ptr->next;
				if(head)
				head->prev = 0;
			}
			else{	
				ptr->prev->next=ptr->next;
				if(ptr->next)
				ptr->next->prev=ptr->prev;
			}
		
			free(ptr->message);
			free(ptr);
			return OK;
		}
	}
	printf("cant [%s]delete", name);
	return NOTOK;
}

void print(void){
	struct mystr *ptr;
	printf("===================\n");
	if(head==NULL){
		printf("No nede in the list.\n");
		printf("==================\n");
		return ;
	}

	for(ptr=head; ptr; ptr=ptr->next){
		printf("name: %s\t age:%d\t message:%s\n", ptr-> name, ptr->age, ptr->message);
	}
	printf("=======================\n");
}

int reverse(void){
	struct mystr *current, *next, *last;
	if(!head) return OK;
	printf("reverse list =====================\n");
	for(last=head; last->next; last=last->next)
		;
	
	current = head;

	while(current != NULL){
		next=current-> next;
		current->next= current->prev;
		current->prev=next;
		current=next;
	}
	head = last;
	return OK;
}

int sort(void){
	char tmp_name[52], tmp_msg[10];
	int tmp_age;
	struct mystr *ptr, *current, *largest;

	if(!head) return OK;

	printf("==============================\n");
	for(current=head; current; current =current->next){
		largest=current;
		for(ptr=current->next; ptr; ptr=ptr->next){
			if(largest->age < ptr->age)
				largest = ptr;
		}
		printf("largest[%s],[%d]\n", largest->name, largest->age);
		
		if(largest != current){
			tmp_age=current->age;
			strcpy(tmp_name, current->name);
			strcpy(tmp_msg, current->message);

			current->age= largest-> age;
			strcpy(current->name, largest->name);
            strcpy(current->message, largest->message);

			largest->age=tmp_age;
            strcpy(largest->name, tmp_name);
            strcpy(largest->message, tmp_msg);
		}
		return OK;
	}	
}
