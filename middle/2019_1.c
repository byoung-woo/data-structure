#include <stdio.h>

int main (){
	int n,m, sum=0;
	
	scanf("%d %d", &n, &m);

	for (; n<=m; n++){
			if(n%2==0){
			sum+=n;
		}
	}
	printf("%d\n", sum);
}
