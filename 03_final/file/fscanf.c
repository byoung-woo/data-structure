#include <stdio.h>

int main(void){
	FILE *fp; char ch; int ret;

	if((fp=fopen("hi2.txt", "r"))==NULL){
		printf("THE file is not opended.\n");
	}
	do{	
	ret= fscanf(fp, "%c", &ch);
	if(ret==EOF)
		break;
	printf("%c", ch);
	}while(1);

	if(fclose(fp)==EOF){
		printf("ERROR closing hi2.txt\n");
	}
	return 0;
}
