#include <stdio.h>

int main (int argc, char *argv[]){
	FILE *rfp;
	FILE *wfp;
	char ch;
	int ret;
	rfp=fopen(argv[1], "r");
	wfp=fopen(argv[2], "w");

	if((rfp= fopen(argv[1], "r"))==NULL){
		printf("cannot open %s file\n", argv[1]);
		return 0;
	}
	if((wfp=fopen(argv[2], "w"))==NULL){
		printf("cannot open %s file\n", argv[2]);
		return 0;
	}

	while(1){
		if(fscanf(rfp, "%c", &ch)!=EOF)
			fprintf(wfp, "%c", ch);
		else
			break;
	}
	fclose (rfp);
	fclose (wfp);
}
