#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define NOTOK 0
#define MSG_SIZE 128

int add(int age, char *name, char *msg);
int delete(char *name);
void print(void);
int save(char *fileName);
void removeLink(void);
int load(char *fileName);

struct mystr{
	struct mystr *next;
	int age;
	char name[52];
	char *message;
};

struct fileStr{
	int age;
	char name[52];
	char msg[MSG_SIZE];
};

struct mystr *head=0;

int main(int argc, char *argv[]){
	if(argc<2){
		printf("Usage: ./a.out 파일명\n");
		return 0;
	}
	add(23, "park", "hello");
	add(28, "kim", "test");
	add(22, "lee", "champios");
	print();
	if(save(argv[1])==NOTOK)
		printf("can't save\n");
	printf("------------------------------------------1\n");
	delete("park");
	delete("kim");
	print();
	printf("------------------------------------------2\n");

	load(argv[1]);
	print();
	printf("-----------------------------------------3\n");
	delete("kim");
	print();
	    printf("-----------------------------------------4\n");
	add(25, "hong", "welcome");
	print();
    printf("-----------------------------------------5\n");
	removeLink();
	print();
	printf("-----------------------------------------6\n");
}

int add(int age, char*name, char*msg){
	struct mystr *new, *last;
	
	if((new=malloc(sizeof(struct mystr)))==NULL)
		return NOTOK;

	new->next = 0;
	new->age = age;
	strcpy(new->name, name);
	new->message=malloc(MSG_SIZE);
	strcpy(new->message, msg);
	
	if(!head)	head=new;

	else {
	for(last=head; last->next; last=last->next)
		;
	last->next=new;
	}
	return OK;
}
int delete(char *name){
	struct mystr *ptr, *prev=0;
	
	for(ptr=head; ptr; prev= ptr, ptr=ptr->next)
	{
		if(!strcmp(name, ptr->name))
		{
			if(head=ptr)	head=ptr->next;
			else			prev->next=ptr->next;
		
			free(ptr->message);
			free(ptr);
			return OK;
		}
	}	
		printf("cant find [%s]delete\n", name);
		return NOTOK;
}

void print(void){
	struct mystr *ptr;
	printf("=====print list==============\n");
	if(head==NULL){
		printf("No nede in the list.\n");
		printf("=====================\n");
		return ;
	}

	for(ptr=head; ptr; ptr=ptr->next){
		printf("name: %s\t age:%d\t message:%s\n", ptr-> name, ptr->age, ptr->message);
	}
	printf("=========================\n");
}

void removeLink(void){
	struct mystr *ptr;
	while(head){
		ptr=head;
		printf("removeLink[%s]\n", ptr->name);
		head=ptr->next;
		free(ptr->message);
		free(ptr);
	}
}
int save(char *fileName){
	FILE *fp;
	struct mystr *ptr;
	struct fileStr record;

	if((fp=fopen(fileName, "w"))==NULL){
		printf("[%s]cant open failed\n", fileName);
		return NOTOK;
	}
	for(ptr=head; ptr; ptr=ptr->next){
		record.age=ptr->age;
		strcpy(record.name, ptr->name);
		strcpy(record.msg, ptr->message);
		fwrite(&record, sizeof(struct fileStr), 1, fp);
	}
	fclose(fp);
	return OK;
		
}
int load(char *fileName){
	FILE *fp;
	struct mystr *ptr;
	struct fileStr record;

	removeLink();
	
	if((fp=fopen(fileName, "r"))==NULL){
		printf("[%s]cant open", fileName);
		return NOTOK;
	}
	
	while((fread(&record, sizeof(struct fileStr), 1, fp))>0){
		add(record.age, record.name, record.msg);
	}
	fclose(fp);	
	return OK;

}
