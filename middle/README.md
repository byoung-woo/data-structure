# 🔧 Pointers & String Algorithms (Middle Term)

포인터 연산과 메모리 주소 제어, 그리고 표준 라이브러리 함수들을 직접 구현해보는 심화 실습입니다.

## 🔍 주요 실습 내용

### 1. 문자열 함수 직접 구현 (String.h Implementation)
표준 라이브러리(`string.h`)의 기능을 포인터로 직접 구현하며 원리를 학습했습니다.
- **`strcpy.c`**: 문자열 복사.
- **`strcat.c`**: 문자열 이어 붙이기.
- **`strcmp.c`**: 문자열 비교.
- **`string.c`**: 문자열 길이 계산(`strlen` 로직).

### 2. 문자열 조작 알고리즘 (String Manipulation)
- **`reverse.c`**: 포인터(`left`, `right`)를 사용하여 문자열을 뒤집는 알고리즘.
- **`deletechar.c` / `deleteChars`**: 특정 문자나 부분 문자열을 삭제하고 배열을 당기는 로직.
- **`findchar.c`**: 특정 문자의 인덱스를 탐색.
- **`changechar.c`**: 특정 위치의 문자를 변경.

### 3. 기타 알고리즘 및 기출 유형
- **`argc.c`**: 메인 함수 인자(`argc`, `argv`) 처리 실습.
- **`2019_*.c`, `2020_*.c`, `2021_*.c`**: 소수 판별(`isPrime`), 자릿수 합계, 특정 패턴 출력 등 중간고