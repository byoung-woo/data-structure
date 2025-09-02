#include <stdio.h>

int main()
{
    float height_cm;
    float result;
    
    // 키 입력 받기
    printf("Enter your height in centimeters: ");
    scanf("%f", &height_cm);
    
    // 계산하기
    result = (height_cm - 100) * 0.9;
    
    // 결과 출력하기
    printf("The result of (height - 100) × 0.9 is: %.2f\n", result);
    
    return 0;
}
