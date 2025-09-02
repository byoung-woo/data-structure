#include <stdio.h>
#include <string.h>
extern int findchar(char*, char);
int main(){
	char ch, str[128];
	int i;
	strcpy(str, "This is test");
	i=findchar(str, 'i');
	printf("%d\n", i);

}

int findchar(char *str, char ch){
	int loc=0, found=0;

	for(; *str!=0; str++){
		if (*str==ch){
			found =1;
				break;
			}
		else
			loc++;
	}
	if(found ==1) return loc;
	else return -1;
}
