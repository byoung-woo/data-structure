#include <stdio.h>
int main()
{
	int num1, num2;
	printf("두 숫자를 입력하시면 비교해드리겠습니다.");
	scanf("%d%d", &num1, &num2);
	if(num1==num2){
		printf("두 숫자가 같습니다.\n");
	}
	else if	(num1>num2){
		printf("%d가 더 큽니다\n", num1);
	}
	else{
		printf("%d가 더 큽니다\n", num2);
	}
}
