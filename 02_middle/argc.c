#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]){
	int n=atoi(argv[1]);
	int m=atoi(argv[3]);

	int j=*argv[2];
	int res;

	if(j=='+')
		res= n+m;

	printf("%d",res);
}
