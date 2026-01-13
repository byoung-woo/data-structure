#include <stdio.h>

int main(){
	char str[512]="It is useful Where a atatement Is needed sYntactically, but no action is reQUired";
	char new[512];
	int i,j;

	for(i=0, j=0; str[i]!='\0'; i++){
		if(str[i]!=' '){
		new[j]=str[i];
		j++;
		}
	new[j]=0;
	}
	printf("%s\n", new);
	
	
}
