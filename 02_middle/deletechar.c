#include <stdio.h>
#include <string.h>

int deletechar(char*cp, char ch){
	for(;*cp!=0; cp++){
		if(*cp==ch)
		break;
	}
	if(*cp==0)
		return -1;
	while(*cp!=0){
		*cp=*(cp+1);
		cp++;
	}
	return 1;
}

int main(){
	char str[128];
	strcpy(str, "This");
	deletechar(str, 'i');
	printf("%s\n", str);	
}
