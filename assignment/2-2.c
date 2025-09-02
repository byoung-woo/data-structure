#include <stdio.h>

int main()
{
    float midterm_score;
    float final_exam_score;
    float average_score;
    
    // 점수 입력 받기
    printf("Enter midterm exam score: ");
    scanf("%f", &midterm_score);
    
    printf("Enter final exam score: ");
    scanf("%f", &final_exam_score);
    
    // 평균 계산하기
    average_score = (midterm_score + final_exam_score) / 2;
    
    // 평균 출력하기
    printf("\nAverage score: %.2f\n", average_score);
    
    return 0;
}
