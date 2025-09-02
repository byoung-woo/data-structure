#include <stdio.h>
#include <string.h>
extern void revstr(char *str);
int main(){
	char str[128];
	
	strcpy(str, "0123456789");
	revstr(str);
	printf("%s\n", str);
	
}

void revstr(char *str){
	
	char *ptr, *left, *right, tmp;
	ptr = str;

	left=ptr;
	for(right=ptr; *right!=0; right++);
	right--;
	
	while(1){
		if (right==left)
			break;

		if((left-1)==right)
			break;
		
		tmp=*right;
		*right = *left;
		*left=tmp;

		right--;
		left++;

	}
}
