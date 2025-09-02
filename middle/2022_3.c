#include <stdio.h>
#include <string.h>
void delChars (char *str1, int n, int m){
	int len = strlen(str1);
	if(n+m>len)
		m=len - n;

	for (int i =n+m; i<=len; i++)
		str1[i-m]=str1[i];
}

int main() {
	char str1[16]="0123456";

	delChars(str1, 2, 1);
	printf("[%s]\n", str1); // 013456

	strcpy(str1, "0123456789");
	delChars (str1, 2, 3);
	printf ("[%s]\n", str1);//0156

	strcpy (str1, "0123456789");
	delChars (str1, 5, 4);
	printf ("[%s]\n", str1);//01234

}
