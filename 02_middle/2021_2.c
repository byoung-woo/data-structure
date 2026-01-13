#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    char str[MAX_SIZE];
    int freq[256] = {0};
    int max_freq = 0; 

    printf("문자열을 입력하세요: ");
    fgets(str, MAX_SIZE, stdin); 
    
    int len = strlen(str);
    
    for(int i = 0; i < len; i++) {
        freq[(unsigned char)str[i]]++;
    }

    for(int i = 0; i < 256; i++) {
        if(freq[i] > max_freq) {
            max_freq = freq[i];
        }
    }
    
    return 0;
}