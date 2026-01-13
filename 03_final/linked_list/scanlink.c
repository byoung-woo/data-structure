#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mystr{
	struct mystr *next, *prev;
	int age;
	char name[52];
	char *message;
};
struct mystr *head = NULL;

int main(void)
{
	struct mystr *ptr, *last;
	int i; 
	for(i=0; i<3; i++){
		ptr= malloc(sizeof(struct mystr));
		ptr->message = malloc(128);
		printf("나이 이름 메시지를 입력하세요\n");
		scanf("%d", &(ptr->age));
		scanf("%s", ptr->name);
		scanf("%s", ptr->message);
		ptr->next=0;
		ptr->prev=0;
		if(head == NULL){	
			head = ptr;
			continue;
		}
		for(last=head; last->next!=0; last = last->next)
		;

		last->next = ptr;
		ptr->prev = last;
	}
		printf("리스트를 출력합니다.\n");
		for(ptr=head; ptr !=0; ptr= ptr->next){
			printf("age = [%d]\n", ptr->age);
			printf("name = [%s]\n", ptr->name);
			printf("message = [%s]\n", ptr->message);
		}
}
