#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){

	int i;
	int num;
	if(argc>1){
		for(i=1; i<argc; i++){
			num = atoi(argv[i]);
			printf("0x%X\n",num);
		}
		printf("\n");
	}
	printf ("%d", atoi(argv[1])+atoi(argv[2]));

}
