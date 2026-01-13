#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]){
	FILE *fp;
	char str[200];
	int count = 0;
	fp = fopen(argv[1], "r");
	
	while(fscanf(fp, "%s",str)!=EOF){
		if((strcmp(argv[2], str))==0){
			count =1;
			
		}
	}
	if(count==1) printf("okay\n");
	else			printf("no\n");
}
