#include <stdio.h>

void sum (int *i, int *j, int *k){
	int sum = *i + *j;
	*k = sum;
}

int main (){
	int num1=5, num2=10, ret=0;
	
	sum(&num1, &num2, &ret);
	printf ("%d와  %d의 합은  %d입니다.\n", num1, num2, ret);

	return 0;
}
