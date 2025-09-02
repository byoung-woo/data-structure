#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
	FILE *fp;
	char str;
	int ret;
	fp=fopen(argv[1], "r");

	if(fp==NULL)
	printf("파일을 오픈할 수 없다.\n");

	do{
		ret=fscanf(fp, "%c", &str);
		if(ret==EOF)
			break;
		printf("%c", str);
	}while(1);
	if(fclose(fp)==EOF){
		printf("파일을 닫을 수 없습니다.");
	}
	return 0;
}
