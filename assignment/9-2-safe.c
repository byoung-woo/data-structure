#include <stdio.h>
#include <string.h>

int main(int argc, char*argv[]){
	FILE *fp;
	char str[100];
	int found=0;
	if((fp=fopen(argv[1], "r"))==NULL){
		printf("[%s]not open\n", argv[1]);
		return 0;
	}
	
	while((fscanf(fp,"%s", str))!=EOF){
		if(!strcmp(argv[2], str))
			found=1;
	}
	if(found==1)
		printf("[%s]파일에 [%s]가 존재합니다.\n",argv[1],argv[2]);
	else printf("not\n");

	fclose(fp);
}
