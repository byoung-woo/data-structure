#include <stdio.h>
#include <ctype.h>
#include <string.h>

// 대소문자를 변경하는 함수
void change_case(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (islower(str[i])) {
            str[i] = toupper(str[i]);
        } else if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    // 역순으로 argv를 처리하여 대소문자 변경 후 출력
    for (int i = argc - 1; i > 0; i--) {
        change_case(argv[i]);
        printf("%s ", argv[i]);
    }
    printf("\n");
    
    return 0;
}
