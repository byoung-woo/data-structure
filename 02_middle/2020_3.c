#include <stdio.h>
#include <string.h>

void deleteChars(char *str, char *ch){
	int len1=strlen(str);
	int len2=strlen(ch);	
	for(int i=0; i<len1; i++){
		for(int j=0; j<len2; j++){
			if(str[i]==ch[j]){
				while(*(str+i)!=0){
					*(str+i)=*(str+i+1);
					i++;
				}
				i=0;
			}
		}
	}	
}
int main(){
	char str[128];

	strcpy (str, "Hello world");
	deleteChars (str, "lo");
	printf ("%s\n", str);

	strcpy (str, "Hello world");
	deleteChars(str, "H");
	printf("%s\n", str);

}
