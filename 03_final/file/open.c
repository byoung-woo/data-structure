#include <stdio.h>

int main (void){
	FILE *fp;
	if((fp=fopen("baic.txt", "w"))==NULL){
		printf("File open failed. \n");
}

	if(fclose(fp)==EOF){
		printf("Error closing basic.txt\n");
	}
	return 0;
}
