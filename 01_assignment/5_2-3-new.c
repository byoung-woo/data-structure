#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){

	char str[512] = "It is useful Where a atatement Is needed sYntactically, but no action is reQUired";
	char new[512];
	int i;
	for(i=0; i<strlen(str);i++){
		if(isupper(str[i]))
		{ new[i] = tolower(str[i]);
		}
		else if(islower(str[i]))
		{ new[i] = toupper(str[i]);
		}
		else
		 new[i] = str[i];
		
	}new[i]='\0';
	for(i=0; i<strlen(new);i++){
	putchar(new[i]);
	}
	printf("\n");
	
}

