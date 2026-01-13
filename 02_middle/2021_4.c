#include <stdio.h>
#include <string.h>
int main() {
	char str[128];
	char *ptr=str;
	scanf("%s", str);

	for(;*ptr!=0; ptr++);

	for(; ptr>=&str[0]; ptr--)
	printf("%c", *ptr);
		

	
}
