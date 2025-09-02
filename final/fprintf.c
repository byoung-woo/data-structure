#include <stdio.h>

int main (void){
	FILE *fp;
	if((fp=fopen("hi.txt", "w"))==NULL){
		printf("The file is not opened\n");
	}


	fprintf(fp, "My code name is %c, my code is %d.\n", 'Z', 123);

	if(fclose(fp)==EOF){
		printf("Error closing basic.txt]n");
	}
	return 0;
}
