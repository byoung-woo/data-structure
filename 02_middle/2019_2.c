#include <stdio.h>

int verify(int a, int b, int c){
	if(a >=60 && b>=60 && c>=60 && (a+b+c)/3>=70)
		return 'A';
	else 
		return 'B';
}

int main () {
	printf("[%c]\n", verify (95,85,90));//A
	printf("[%c]\n", verify (90,85,55));//B
	printf("[%c]\n", verify (71,85,74));//A
    printf("[%c]\n", verify (90,60,60));//A

}
