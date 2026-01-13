#include <stdio.h>

int calcSum(int p, int q){
	int sum=0;
	for(int i=1; i<=p; i++)
		if(i%q==0)
		sum += i;
	return sum;

}
int main(){


	int n,m;
	scanf("%d %d", &n, &m);

	printf("%d\n", calcSum(n,m));
}
