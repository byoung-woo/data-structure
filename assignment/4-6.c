#include <stdio.h>

int main(){
	char ch;
	int i,j;
	for(i=0;i<5;i++)
	{
		scanf("%c",&ch);
		getchar();
		for(j=0;j<(int)ch;j++)
		{
			printf("+");
		} 
	 printf("\n");	
	}
}
