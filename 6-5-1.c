#include <stdio.h>

int main(){
	char str[200]="This";
	char *ptr=str;
	int len=0;
	for(; *ptr!='\0'; ptr++)
	len++;
	
	for(ptr=str+len-1; ptr >= str; ptr--)
	printf("%c", *ptr);
	
	printf("\n");

	

}

















