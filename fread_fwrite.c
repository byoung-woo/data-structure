#include <stdio.h>

int main (void){
	char str[128]; int ret;
	FILE *fpSrc=fopen("basic.txt","r");
	FILE *fpDst=fopen("copy2","w");
	
	if(fpSrc==NULL||fpDst==NULL){
		printf("The file is not opened.\n");
		return 0;
	}
	while(

	fread(str, sizeof(str), fpSrc)!=NULL){
		fputs(str, fpDst);
	}
	fclose(spSrc); fclose(fpDst);
	return0;
}

