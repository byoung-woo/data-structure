#include <stdio.h>
extern int myStrcpy(char*, char *);
int main(){

	char src[128]="This",dst[128];

	myStrcpy(dst, src);
	printf("%s\n", dst);
}

int myStrcpy(char*dest, char *src){
	while(*src!=0){
		*dest = *src;
		dest++;
		src++;
	}
}
