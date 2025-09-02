#include <stdio.h>

int hak (int score){
	if (score >= 90)
	return 'A';
	else if (score >= 80)
	return 'B';
	else if (score >= 70)
	return 'C';
	else
	return 'F';
}

int main () {
	int score=0;
	printf("성적을 입력하시오 : ");
	scanf("%d", &score);

	char hakjum = hak(score);
	printf("당신의 학점은 %c\n입니다.", hakjum);


}
