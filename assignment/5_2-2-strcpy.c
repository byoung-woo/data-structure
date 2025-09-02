#include <stdio.h>
#include <string.h>
int main(){

	char orig[512];
	strcpy (orig, "It is useful Where a statement Is needed sYntactically, but no actio is reQUired");
	char new[512];
	int i,j;
	printf("%s\n", orig);
	printf("공백 제외 문자열 : ");
	
	for(i=0, j=0; orig[i]!='\0'; i++)
		if(orig[i]!=' '){
	  		new[j]=orig[i];
				j++;}	


	new[j]=0;
	printf("%s\n", new);
}
