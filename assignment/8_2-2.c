#include <stdio.h>

int main() {
    int num = 5;
    int right_shift_1, right_shift_2, right_shift_3;
    int left_shift_1, left_shift_2, left_shift_3;

    // 오른쪽으로 1, 2, 3번 쉬프트
    right_shift_1 = num >> 1;
    right_shift_2 = num >> 2;
    right_shift_3 = num >> 3;
    
    // 왼쪽으로 1, 2, 3번 쉬프트
    left_shift_1 = num << 1;
    left_shift_2 = num << 2;
    left_shift_3 = num << 3;

    // 결과 출력
    printf("Original number: %d\n", num);
    printf("Right shift by 1: %d\n", right_shift_1);
    printf("Right shift by 2: %d\n", right_shift_2);
    printf("Right shift by 3: %d\n", right_shift_3);
    printf("Left shift by 1: %d\n", left_shift_1);
    printf("Left shift by 2: %d\n", left_shift_2);
    printf("Left shift by 3: %d\n", left_shift_3);

    return 0;
}
