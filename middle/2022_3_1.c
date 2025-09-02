#include <stdio.h>

void delChars(char *str1, int n, int m){
	char *new;
	int len=0;
	while(*str1!=0)
		len++;
	for(int i=0; i<n; i++)
		new[i]=str1[i];
	for(int i=0; )
}

int main() {
    char str1[16]="0123456";

    delChars(str1, 2, 1);
    printf("[%s]\n", str1); // 013456

    strcpy(str1, "0123456");
    delChars (str1, 2, 3);
    printf ("[%s]\n", str1);//0156

    strcpy (str1, "0123456");
    delChars (str1, 5, 4);
    printf ("[%s]\n", str1);//01234

}

