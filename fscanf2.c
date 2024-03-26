#include <stdio.h>

int main (void){
	FILE *fp;
	char str[128];
	int ret;

	if((fp=fopen("hi2.txt", "r"))==NULL){
		printf("THE file (basic.txt) is not opened.\n");
	}

	do{
		ret=fscanf(fp,"%s", str);
		if(ret==EOF)
			break;
		printf("%s\n", str);
	}while (1);

	if (fclose(fp)==EOF){
		printf("에러\n");
	}
}

