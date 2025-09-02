#include <stdio.h>
#include <string.h>

void deleteChars(char *str, char *ch){
	int len =0, len2=0;
	while(str[len]!=0)
		len++;
	while(ch[len2]!=0)
		len2++;
	for(int i=0; i<len; i++){
		for(int j=0; j<len2; j++){
			if(*(str+i)==*(ch+j)){
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

