#include <stdio.h>

int main()
{
    int student_number;
    int korean_score;
    int english_score;
    
    // 학생 정보 입력 받기
    printf("Enter student number: ");
    scanf("%d", &student_number);
    
    printf("Enter Korean score: ");
    scanf("%d", &korean_score);
    
    printf("Enter English score: ");
    scanf("%d", &english_score);
    
    // 학생 정보 출력하기
    printf("\nStudent Information:\n");
    printf("Student Number: %d\n", student_number);
    printf("Korean Score: %d\n", korean_score);
    printf("English Score: %d\n", english_score);
    
    return 0;
}
