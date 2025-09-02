# assignment — 자료구조 과제 모음

이 디렉터리는 **자료구조 과제 코드**를 모아둔 공간입니다. 각 소스는 독립적으로 컴파일될 수 있으며, 필요 시 여러 파일을 함께 빌드하세요. 본 README는 **빠른 실행 가이드**, **파일 역할 정리 템플릿**, **코드 품질 체크리스트**를 제공합니다.

---

## 📁 파일/역할 정리 템플릿

> 아래 표를 실제 파일명과 설명으로 채워 사용하세요. (예시는 삭제해도 됩니다)

| 파일명 | 자료구조 | 주요 기능(삽입/삭제/탐색 등) | 입출력 형식 요약 | 비고 |
|---|---|---|---|---|
| `singly_list.c` | 단일 연결리스트 | 삽입/삭제/탐색/역순출력 | 표준입력에서 명령 읽기 | 예시 |
| `doubly_list.c` | 이중 연결리스트 | 삽입/삭제/양방향 순회 | 파일 입력 지원 | 예시 |
| `stack_array.c` | 스택(배열) | push/pop/peek | 테스트 케이스 내장 | 예시 |
| `queue_ll.c` | 큐(연결리스트) | enqueue/dequeue | 표준입력 숫자 처리 | 예시 |

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

### 3) 디버그 & 런타임 점검 (권장)
메모리/UB 오류 검출: (GCC/Clang, Linux/WSL/macOS)
```bash
gcc -g -O1 -std=c11 -Wall -Wextra -fsanitize=address,undefined <file.c> -o app
./app
```

> Windows MinGW 환경에서는 `-fsanitize` 지원이 제한될 수 있습니다. WSL을 권장합니다.

---

## 🧪 입출력 예시 템플릿

각 과제 파일 상단 주석 또는 본 README에 **예시를 기록**해두면 복습이 쉬워집니다.

```txt
# 예: doubly_list.c
입력:
insert kim 20
insert park 21
print
delete kim
print

출력:
kim 20
park 21
park 21
```

---

## 🧹 코드 품질 체크리스트

- [ ] **입력 폭 제한**: `scanf("%31s", name);` 처럼 버퍼 크기-1 지정
- [ ] **메모리 관리**: `malloc` 실패 체크, 모든 경로에서 `free`
- [ ] **경계 조건**: 빈 구조/단일 노드/중복 키/없는 키 삭제 시 처리
- [ ] **함수 분리**: 로직(삽입/삭제/탐색) vs. 입출력(UI) 분리
- [ ] **반환값 설계**: `OK/NOK` 또는 `enum`으로 성공/실패 구분
- [ ] **헤더 가드**: 사용자 헤더 `.h`에 `#ifndef/#define/#endif`
- [ ] **테스트**: 최소 5개 이상 시나리오(정상/예외) 자동화 또는 스크립트

---

## 🔧 디버깅 팁

- **세그폴트** 발생 시: `-g`로 빌드 후 `gdb ./app` → `run` → 크래시 라인 확인
- **무한루프** 의심: 증감식/종료 조건 로깅(`fprintf(stderr, ...)`)으로 추적
- **메모리 릭**: `valgrind --leak-check=full ./app` (Linux/WSL)

---

## 📦 권장 디렉터리 구조 (선택)

```
assignment/
├─ list/
│  ├─ singly_list.c
│  ├─ doubly_list.c
│  └─ list.h
├─ stack/
│  ├─ stack_array.c
│  └─ stack_ll.c
├─ queue/
│  ├─ queue_array.c
│  └─ queue_ll.c
└─ README.md
```

---

## 📝 커밋 가이드 (선택)

- 메시지 예: `list: fix delete bug (prev->next not updated)`
- 한 커밋에는 **하나의 논리 변경**만 담기
- PR/이슈에 **재현 절차**와 **테스트 결과** 첨부

---

## 라이선스

별도 명시가 없다면 개인 학습 용도로 사용하세요. 외부 배포 시 라이선스 파일 추가를 권장합니다.
