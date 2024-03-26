#include <stdio.h>
int main()
{
	int score;
	printf("점수를 입력하시오 :");
	scanf("%d", &score);

	if(score>=90&&score<=100){
	printf("A학점 입니다.\n");
	}
	else if (score>=80&&score<=89){
	printf("B학점 입니다.\n");
	}
	else if (score>=70&&score<=79){
	printf("C학점 입니다.\n");
	}
	else if (score>=60&&score<=69){
	printf("D학점 입니다.\n");
	}
	else {
	printf("F학점 입니다.\n");
	}
}
