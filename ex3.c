#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mystr {
	struct mystr *next, *prev;
	int age;
	char name[52];
	char *message;
}*head;

//struct mystr *head;
void print(void);

int main(){
	struct mystr *ptr1, *ptr2, *ptr3;
	
	ptr1 = malloc (sizeof(struct mystr));
	ptr1->age = 20;
	strcpy (ptr1->name, "Hong GilDong");
	ptr1->message = malloc (128);
	strcpy (ptr1->message, "test message");

	ptr2 = malloc (sizeof(struct mystr));
	ptr2->age = 22;
	strcpy (ptr2->name, "Kim ChulSu");
	ptr2->message = malloc (128);
	strcpy (ptr2->message, "hello workd");
	
	
	ptr1 -> next = ptr2;
	ptr1 -> prev = 0;

	ptr2 -> next = 0;
	ptr2 -> prev = ptr1;
	
	head = ptr1;	
	print();
	
	for(ptr1=head; ptr1->next!=0; ptr1=ptr1->next)
	;
	
	free (ptr1->message);
	ptr1->prev->next = 0;
	free (ptr1);
	printf("\n----------------------\n");
	print();	
}
void print(void){
	
	struct mystr *ptr;
	for (ptr= head; ptr !=0; ptr = ptr->next){
		printf("age=[%d]\n", ptr-> age);
		printf("name=[%s]\n", ptr-> name);
		printf("message=[%s]\n\n", ptr-> message);
	}
}
