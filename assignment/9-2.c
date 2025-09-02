#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
	FILE *fp;
	char str[200];
	int contain = 0;
	fp=fopen(argv[1], "r");

	while(fscanf(fp, "%s", str) != EOF){
		if(strcmp(argv[2], str)==0){
			contain = 1;
			break;
		}
	}
	if(contain == 1)
		printf("%s exist.\n", argv[2]);
	else
		printf("%s does not exist.\n", argv[2]);
			
}
