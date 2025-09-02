#include <stdio.h>
int main (void){
	char str[128]; int ret;
	FILE *fpSrc=fopen("basic.txt", "r");
	FILE *fpDst=fopen("basic_copy2", "w");

	if((fpSrc==NULL||fpDst==NULL)){
		printf("THe file is not is not opend.\n");
		return 0;
	}
	while(fgets(str, sizeof(str), fpSrc)!=NULL){
		fputs(str, fpDst);
	}
	fclose(fpSrc); fclose(fpDst);
	return 0;
}
