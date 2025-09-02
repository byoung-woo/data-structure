# middle — 중간고사 대비 연습 코드

이 디렉터리는 **중간고사 대비용 자료구조 연습 코드**를 모아둔 공간입니다. 각 예제는 C 언어로 작성되었으며, 단일 파일 또는 다중 파일 구성일 수 있습니다.

---

## 📁 파일/역할 정리 템플릿

| 파일명 | 자료구조/주제 | 주요 기능(삽입/삭제/탐색 등) | 입출력 형식 요약 | 비고 |
|---|---|---|---|---|
| `example1.c` | 스택/큐 | push/pop/enqueue/dequeue | 표준입력 명령 기반 | 예시 |
| `example2.c` | 리스트 | 삽입/삭제/역순 출력 | 파일 입력 지원 | 예시 |

> 실제 파일명과 기능으로 표를 채워 넣으세요.

---

## 🚀 빌드 & 실행

### 1) 단일 파일
```bash
gcc -Wall -Wextra -O2 -std=c11 <file.c> -o app
./app
```

### 2) 여러 파일
```bash
gcc -Wall -Wextra -O2 -std=c11 file1.c file2.c -o app
./app
```

### 3) 디버깅/런타임 점검(권장)
```bash
gcc -g -O1 -std=c11 -Wall -Wextra -fsanitize=address,undefined <file.c> -o app
./app
```

---

## 🧪 입출력 예시 템플릿

```txt
입력:
push 10
push 20
pop
print

출력:
20
10
```

---

## 🧹 코드 품질 체크리스트

- [ ] `scanf` 폭 제한 적용 (예: `"%31s"`)
- [ ] `malloc` 실패 처리 및 모든 경로에서 `free`
- [ ] 빈 구조/단일 노드/중복 키/에러 입력 처리
- [ ] 로직 함수 vs. I/O 함수 분리
- [ ] 성공/실패 반환값 일관화 (`OK/NOK` 또는 `enum`)
- [ ] 사용자 헤더 가드 적용
- [ ] 최소 5개 케이스 테스트

---

## 🔧 디버깅 팁

- 세그폴트: `-g` 빌드 → `gdb ./app`
- 무한루프 의심: 루프 카운터/포인터 로깅
- 메모리 릭: `valgrind --leak-check=full ./app` (Linux/WSL)

---

## 📦 예시 디렉터리 구조(선택)

```
middle/
├─ stack_queue/
│  ├─ stack_array.c
│  ├─ queue_ll.c
│  └─ common.h
├─ list/
│  ├─ singly.c
│  ├─ doubly.c
│  └─ list.h
└─ README.md
```
