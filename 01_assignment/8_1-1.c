#include <stdio.h>

struct mystr{
	char name[100];
	int number;
	int korea;
	int english;
	float average;
};

void readData(struct mystr *ptr){
	printf("이름, 번호, 국어성적, 영어 성적 순으로 3개 입력하시요\n");
	for(int i=0; i<3; i++){
		scanf("%s", ptr->name);
		scanf("%d", &(ptr->number));
		scanf("%d", &(ptr->korea));
		scanf("%d", &(ptr->english));
		ptr++;
	}
}
void calAverage(struct mystr *ptr){
	for(int i=0; i<3; i++){
		ptr[i].average = (ptr[i].korea+ptr[i].english)/2;
	}
}

void printData(struct mystr *ptr){
		printf ("\n");
	for(int i=0; i<3; i++){
		printf("이름 : %s\n", ptr[i].name);
        printf("번호 : %d\n", ptr[i].number);
        printf("국어 점수 : %d\n", ptr[i].korea);
        printf("영어 점수 : %d\n", ptr[i].english);
        printf("평균 : %.2f\n", ptr[i].average);
		printf("\n");
	}
}
int main(){
	struct mystr data[3];
	readData (data);
	calAverage (data);
	printData(data);
}
