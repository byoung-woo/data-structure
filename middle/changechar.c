#include <stdio.h>
#include <string.h>
int changechar(char*str, int i, char ch){
	int len=0;
	for (; *(str+len);len++);
	if(i>(len+1))
	return -1;
	else 
		*(str+i)=ch;
	return 1;
}


int main(){
	char str[128];
	int ret;
	
	strcpy(str, "Hello World");
	ret= changechar(str, 5, 'K');

	if(ret==1)
		printf("%s\n", str);
	else printf("can't change.\n");

}


