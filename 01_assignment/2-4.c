#include <stdio.h>

int main()
{
    int months;
    long long hours, minutes, seconds;
    
    // 개월 수 입력 받기
    printf("Enter number of months: ");
    scanf("%d", &months);
    
    // 시간, 분, 초로 환산
    hours = months * 30 * 24; // 1개월 = 30일, 1일 = 24시간
    minutes = hours * 60; // 1시간 = 60분
    seconds = minutes * 60; // 1분 = 60초
    
    // 결과 출력
    printf("\n%d months is equivalent to:\n", months);
    printf("%lld hours\n", hours);
    printf("%lld minutes\n", minutes);
    printf("%lld seconds\n", seconds);
    
    return 0;
}
