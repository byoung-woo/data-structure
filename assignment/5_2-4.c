#include <stdio.h>
#include <string.h>
//#include <ctype.h>

int main(){
	char command[512];
	int i, j;
	while(1){
		printf("명령어를 입력하시오 : 더하기, 빼기, 나누기, 곱하기, 취소\n");
		scanf("%s", command);

		if (strcmp(command,"더하기")==0){
			printf("두 개의 숫자를 입력하시오\n");
			scanf("%d %d", &i, &j);
			printf("%d\n", i+j);
		}
		else if (strcmp(command,"빼기")==0){
            printf("두 개의 숫자를 입력하시오\n");
            scanf("%d %d", &i, &j);
            printf("%d\n", i-j);
        }
		else if (strcmp(command,"나누기")==0){
            printf("두 개의 숫자를 입력하시오\n");
            scanf("%d %d", &i, &j);
            printf("%d\n", i/j);
        }
		else if (strcmp(command,"곱하기")==0){
            printf("두 개의 숫자를 입력하시오\n");
            scanf("%d %d", &i, &j);
            printf("%d\n", i*j);
        }
		else if (strcmp(command,"취소")==0){
			break;
		}
		else
			printf("다시 ");
}


}
