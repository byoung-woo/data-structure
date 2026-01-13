#include <stdio.h>
#define Maxlen 16

int insert(char *str1, char *str2, int n){
	int len1 =0, len2=0;
	while(str1[len1]!='\0')
		len1++;
	while(str2[len2]!='\0')
		len2++;
	if((len1+len2)>Maxlen){
	return 0;
}
	for(int i =len1-1; i>=n; i--)
		*(str1+i+len2)=*(str1+i);
	for(int j = 0; j<len2; j++)
		*(str1+j+n)=*(str2+j);

}
int main(){
	char str1[100]="hello";
	char str2[100]= "workd";
	
	insert (str1, str2, 5);
	printf ("[%s]\n", str1);

	
}
