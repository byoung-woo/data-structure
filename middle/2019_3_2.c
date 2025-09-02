#include <stdio.h>
#include <string.h>

void Reverse(char *array){
	int len = 0;
	while (array[len]!=0)
		len++;
	for(int i= len-1; i>=0; i--)
		printf("%c", array[i]);
		
}

void even(char *array){
	int len1 = 0;
    while (array[len1]!=0)
        len1++;

	for (int i =1; i <len1; i+=2 )
		printf("%c", array[i]);
}


int main(){
    char str1[] = "01234567";
    char str2[] = "ABCDE";

    Reverse (str1); //출력되는 내용 : 76543210
    Reverse (str2); //출력되는 내용 : EDCBA

    even (str1); //출력되는 내용 : 0246
    even (str2); //출력되는 내용 : ACE
}

              
