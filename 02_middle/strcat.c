#include <stdio.h>
#include <string.h>

extern int mystrcat(char*, char*);

int main(){
	char buf1[128], buf2[128];

	strcpy (buf1, "Hello ");
	strcpy (buf2, "World");
	mystrcat(buf1, buf2);

	printf("%s\n", buf1);
}

int mystrcat(char *s1, char *s2){
	while(*s1!=0)
		s1++;

	while(*s2!=0){
		*s1=*s2;
		s1++;
		s2++;
	}
	
}
