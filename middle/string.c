#include <stdio.h>

int myStrlen (char *str){
	int count;
	for (count=0; *str; str++)
		count++;

	return(count);
}

int main(){
	char string[128]="This";
	int i;

	i=myStrlen (string);
	printf("%d\n", i);
}
