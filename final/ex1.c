#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mystr {
	struct mystr *next, *prev;
	int age;
	char name[52];
	char *message;
};
int main(){
	struct mystr *head;
	
	head = malloc (sizeof(struct mystr));
	
	head->age = 20;
	strcpy (head->name, "Hong GilDong");
	
	head->message = malloc (128);
	strcpy (head->message, "test message");
	
	printf ("age = [%d]\n", head->age);
    printf ("name = [%s]\n", head->name);
    printf ("message = [%s]\n", head->message);

}
	
