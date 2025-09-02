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
int sort(void);
int findAge(char *name);

struct mystr *head=0;

int main(){
	int age;
	char name[10], message[10], command[10];
	 
	while(1){
		printf("input command.(add, delete, reverse, sort, print, end) : ");
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
	    else if(!strcmp(command, "sort")){
            sort();
        }
		else if(!strcmp(command, "findAge")){
			printf("\tinput name : ");
            scanf("%s",name);
			printf("%d\n", findAge(name));
          
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

	if((new=malloc(sizeof(struct mystr)))==NULL){
		return NOTOK;
	}
	new->next= new->prev = 0;
	new->age=age;
	strcpy(new->name, name);
	new->message=malloc(MSG_SIZE);
	strcpy(new->message, msg);
	
	if(!head){ 
		head=new;
		return OK;
	}
	for(last=head; last->next; last=last->next)
		;
	last->next=new;
	return OK;
}
int delete(char *name){
	struct mystr *ptr;
	
	for(ptr=head; ptr; ptr=ptr->next)
	{
		if(!strcmp(ptr->name, name)){
			if(ptr->prev==0){
				head=ptr->next;
				if(head) head->prev=0;
			}
			else{
				ptr->prev->next=ptr->next;
				if(ptr->next) ptr->next->prev=ptr->prev;
			}	
			free(ptr->message);
			free(ptr);
			printf("[%s]delete fault", name);		
			return OK;
		}
	}

	return NOTOK;
}
void print(void){
	struct mystr *ptr;

	if(!head){
		printf("not node=================\n");
	}
	for(ptr=head; ptr; ptr=ptr->next){
		printf("\tname:%s \tmessage: %s \tage: %d\n", ptr->name, ptr->message, ptr->age);
	}
}
int reverse(void){
	struct mystr *current, *next, *last;

	if(!head) return OK;

	
	for(last=head; last->next; last=last->next)
		;
	current=head;
	while(current!=NULL){
		next=current->next;
		current->next=current->prev;
	return OK;
}
}
int sort(void){
	int tmp_age;
	char tmp_name[100], tmp_msg[55];
	struct mystr *current, *ptr, *largest;
	
	if(!head) return OK;
	for(current=head; current; current=current->next){
		largest=current;

		for(ptr=current; ptr; ptr=ptr->next){
			if(largest->age < ptr->age)
				largest=ptr;
		}	
		printf("largest[%s][%d]\n", largest->name, largest->age);

		if(largest !=current){
			
			tmp_age=current->age;
			strcpy(tmp_name, current->name);
			strcpy(tmp_msg, current->message);

			current->age= largest->age;
			strcpy(current->name, largest->name);
            strcpy(current->message, largest->message);

			largest->age=tmp_age;
	        strcpy(largest->name, tmp_name);
            strcpy(largest->message, tmp_msg);

		}
		

		
	}return OK;
}
int findAge(char *name){
	struct mystr *ptr;
	int min;
	for(ptr=head; ptr; ptr=ptr->next){
		if(!strcmp(ptr->name, name)){
			min=ptr->age;
			return min;
		}
}
	return NOTOK;
}
int insert(char *toName, char *name, int age, char *msg){
	struct mystr *new, *ptr;
	int found =0;
	if((new=malloc(sizeof(struct mystr)))==NULL) return NOTOK;

	new->next=new->prev=0;
	new->age=age;
    strcpy(new->name, name);
    new->message=malloc(MSG_SIZE);
    strcpy(new->message, msg);
	
	for(ptr=head; ptr; ptr=ptr->next){
		if(!strcmp(ptr->name, toName)){
			if(ptr->prev){
				ptr->prev->next= new;
			}	
			else{
				head=new;
			}
			new->prev=ptr->prev;
			new->next=ptr;
			ptr->prev=new;
			found =1;	
		}
	}
	if(found==0){
	free(new->message);
	free(new);
	return NOTOK;
	}
	return OK;
}
int delodds(){
	struct mystr *ptr, *next;
	int index= 0;
	ptr=head;
	while(ptr){
		if(index%2==1){
			next= ptr->next;
			if(ptr->prev)
				ptr->prev->next=next;
			else head=next;
			if(next) next->prev=ptr->prev;

			free(ptr->message);
			free(ptr);
		}
		else{
		ptr=ptr->next;
		}
		
		index++;
	}
	return OK;
}
