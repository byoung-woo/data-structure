#include <stdio.h>
int main(){
	int num[10];
	int i, sum=0;
	float avg;
	
	printf("10개의 점수 입력 : ");
	
	for(i=0; i<10;i++)
	scanf("%d", &num[i]);
	
	printf("\n");

	for(i=sum=0; i<10; i++)
	sum+=num[i];
	
	avg = (float)sum/10;
	printf("평균 : %.2f\n",avg);
}



