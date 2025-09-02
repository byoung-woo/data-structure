#include <stdio.h>
#include <string.h>

void printReverse (char * array){
	char *ptr;
	ptr = array;
	char *left, *right, tmp;
	left = ptr;
	//printf("letf= %s\n", left);
	for(right=array; *right !=0; right++)
		;		
	right--;
	//printf("right = %s\n", right);	
	while(1){
		if(right==left)
			break;
		if((left-1)==right)
			break;
	tmp = *right;
	*right = *left;
	*left = tmp;

	left++;
	right--;	
	}
	printf("%s\n", ptr);
	
}
void printEven (char *array){
	char *ptr2;
	ptr2 = array;
	int len=strlen(ptr2);
	for (int i=1; i<len; i+=2){
	printf("%c", ptr2[i]);
	}	printf("\n");
	
}

int main(){
	char str1[] = "01234567";
	char str2[] = "ABCDE";

	printReverse (str1); //출력되는 내용 : 76543210
	printReverse (str2); //출력되는 내용 : EDCBA

	printEven (str1); //출력되는 내용 : 0246
	printEven (str2); //출력되는 내용 : ACE
}
