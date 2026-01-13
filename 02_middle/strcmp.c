#include <stdio.h>
#include <string.h>
extern int myStrcmp();
int main(){
	char buf1[128], buf2[128];
	int i;

	strcpy (buf1, "Hello");
	strcpy (buf2, "Hallo");

	i=myStrcmp(buf1, buf2);

	printf("%d\n", i);
}

int myStrcmp(char *s1, char *s2){
	while(*s1==*s2){
		if(*s1==0)
		return (0);
		s1++;
		s2++;
		
	}
	return (1);

}
