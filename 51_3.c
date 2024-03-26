#include <stdio.h>

int main()
{

	int i, j, high;
	int num01[10], num02[10];
	
	for(i=0; i<10;i++)
	{
	scanf("%d", &num01[i]);
	}
	for(i=0;i<10;i++)
	{	high = 0;
		for(j=0; j<10; j++)
			{
			if(num01[j]>num01[high])
			high = j;
			}
	num02[i]=num01[high];
	num01[high]=-1;
	}
	for(i=0; i<10; i++)
	printf("%d\t", num02[i]);
	
	printf("\n");
	
}
