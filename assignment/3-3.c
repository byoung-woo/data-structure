#include <stdio.h>
int main()
{
	int gook, young, su;
	float pung;
	printf("국어 성적을 입력하시오 :");
	scanf("%d", &gook);
	printf("영어성적을 입력하시오 :");
	scanf("%d", &young);
	printf("수학성적을 입력하시오 :");
	scanf("%d", &su);

	pung=(gook+young+su)/3;	
	if (gook>=60&&young>=60&&su>=60&&pung>=70){
	printf("합격\n");
	}
	else {
	printf("불합격\n");
	}
	

}
