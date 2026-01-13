#include <stdio.h>
#include <string.h>
int freq (char *str, char ch){
	int cnt =0;
	int len =0;
	while(str[len]!='\0'){
		len++;
	}
	for(int i =0; i<len; i++){
		if(str[i]==ch)
			cnt++;
	}
	return cnt;

}
int main(){
    char str[100];
    strcpy(str, "Hello world");
    printf("%d\n", freq(str, 'd'));
}

