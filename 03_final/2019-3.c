#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NOK -1
#define OK 1
struct mystr{
	struct mystr *next,*prev;
	int age;
	char *name;
} *head;
int addNode(char *name, int age){
	struct mystr *new,*last;

	if( (new=malloc(sizeof(struct mystr))) == NULL)
		return (NOK);
	new->next = new->prev = 0;
	new->age=age;
	new->name=malloc(18);
	strcpy(new->name,name);

	if(head==0){
		head=new;
		return (OK);
	}
	for(last=head;last->next!=0;last=last->next)
		;
	last->next=new;
	new->prev=last;
	return (OK);
}
	
	
	
void printNodes(){
	struct mystr *ptr;
	for(ptr=head;ptr!=0;ptr=ptr->next)
		printf("%d %s\n",ptr->age, ptr->name);
}
void printReverse(){
	struct mystr *last,*next,*current;
	//if(head==0)
		//return 0;
	for(last=head;last->next!=0;last=last->next)
		;
	current=head;
	while( current != NULL){
		next=current->next;
		current->next=current->prev;
		current->prev=next;
		current=next;
	}
	head=last;
	printNodes();
}

int findAge(char *name){
	struct mystr *ptr;
	int min;
	for(ptr=head;ptr!=0;ptr=ptr->next){
		if(!strcmp(ptr->name,name)){
			min=ptr->age;
			return min;
		}
	}
	return -1;
}

int swapNodes(char *name1, char *name2){
	struct mystr *ptr,*ptr2,*tmp1,*tmp2,*tmp;
	tmp=malloc(sizeof(struct mystr));
	for(ptr=head;ptr!=0;tmp1=ptr,ptr=ptr->next)
		if(!strcmp(ptr->name,name1))
			break;
	for(ptr2=head;ptr2!=0;tmp2=ptr2,ptr2=ptr2->next)
		if(!strcmp(ptr2->name,name2))
			break;
	strcpy(tmp->name,tmp1->name);
	strcpy(tmp1->name,tmp2->name);
	strcpy(tmp2->name,tmp->name);
	

}
int main(){
	addNode("kim",20);
	addNode("park", 21);
	addNode("choi", 22);
	addNode("ahn", 23);
	printNodes();
	printReverse();
	printf("%d\n", findAge("choi") );
	printf("%d\n", findAge("hong") );
	printf("--------------\n");
	swapNodes("kim", "park");
	printNodes();
}
