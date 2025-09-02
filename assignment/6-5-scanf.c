#include <stdio.h>

int main(){
	char str[200];
	char *ptr=str;
	int len =0;
	
	printf("단어를 입력하시오 : ");
	scanf("%s", str);

	for (ptr; *ptr !='\0'; ptr++){
		len++;
	}
	for (ptr = str + len - 1; ptr >= str; ptr--){
	printf("%c", *ptr);
	}	
	printf("\n");
}
