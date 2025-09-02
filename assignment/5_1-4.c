#include <stdio.h>

int main()
{
	int num[10], max, min, i;

	for(i=0;i<10;i++)
	{
		scanf("%d",&num[i]);
	}
	max=min=num[0];
	for(i=0; i<10; i++)
	{
		if(num[i]>max)
		max=num[i];
		
		if(num[i]<min)
		min=num[i];
	}
	
	
	printf("가장큰수는 : %d\n", max);
	printf("가장 작은수는 : %d\n", min);

}

