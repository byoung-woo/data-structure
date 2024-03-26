#include <stdio.h>

int main(){
	int i,sum;
	printf("<한달에 100원씩 30년을 저축할때 모은금액>\n");
	for(i=1;1<=30;i++)
	{ sum += 100*12*i;

		if(i==30)
		break;
	}	printf("%d년 동안 모은 금액 %d원\n",i,sum);

}

