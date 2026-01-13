# 🔗 Data Structures & File I/O (Final Term)

동적 할당(`malloc`)을 이용해 연결 리스트(Linked List)를 구현하고, 메모리 상의 데이터를 파일 시스템에 저장/복원하는 파일 입출력을 심화 학습한 과정입니다.

---

## 📚 핵심 실습 및 구현 내용

### 1) 연결 리스트 심화 구현 (Advanced Linked List)
연결 리스트의 삽입 위치 선택, 양방향 탐색, 정렬 알고리즘을 직접 설계하며 포인터 기반 메모리 구조를 익혔습니다.

#### ✅ 노드 추가 알고리즘
- **add.c**: 리스트의 끝(Tail)에 노드를 추가하는 일반적인 방식  
- **first_add.c**: 리스트의 맨 앞(Head)에 노드를 추가하여 시간 복잡도를 유리하게 만드는 방식  

#### ✅ 연결 구조의 확장
- **single.c**: `next` 포인터만을 이용한 단일 연결 리스트 기초  
- **ex1.c**, **ex2.c**, **ex3.c**: 구조체 포인터와 `malloc`을 활용한 노드 생성 및 수동 연결 실습  
- **이중 연결 리스트(Doubly Linked List)**: `prev`와 `next` 포인터를 함께 관리하여 양방향 탐색과 삭제 로직을 구현  

---

### 2) 동적 리스트 관리 시스템 (Integrated CRUD Systems)
사용자 입력(메뉴/커맨드)을 기반으로 실시간으로 노드를 추가·삭제·출력하고, `free`를 포함한 메모리 해제를 통해 누수를 방지하는 흐름을 구현했습니다.

- **scan_add_delete_1.c**, **scan_add_delete_2.c**: add/delete/print 메뉴 제공 + 삭제 시 `free` 처리 포함  
- **scanlink.c**: `scanf`로 리스트를 동적으로 생성하고 출력하는 실습  

---

### 3) 리스트 조작 알고리즘 (Sorting & Reversing)
포인터 연결을 조작해 리스트의 순서를 바꾸는 로직을 학습했습니다.

- **reverse_sort_1.c**, **reverse_sort_2.c**, **reverse_sort_3.c**
  - **Reverse**: 연결 방향을 실제로 뒤집어 리스트 순서를 반전
  - **Sort**: 나이 등 특정 기준으로 데이터를 비교해 노드 위치를 재배치하는 정렬 로직

---

### 4) 데이터 영속성 및 파일 입출력 (Data Persistence)
프로그램 종료 후에도 데이터가 유지되도록, 구조체 데이터를 파일에 기록하고 다시 읽어 리스트를 복원하는 기능을 구현했습니다.

- **save_load_1.c**, **save_load_2.c**: 리스트 전체를 파일에 저장(save)하고 재시작 시 로드(load)하여 복원하는 직렬화 로직  

#### ✅ 파일 제어 함수 활용
- **fprintf.c**, **fscanf.c**, **fscanf2.c**: 서식화된 텍스트 기반 입출력 실습  
- **fread_fwrite.c**: 구조체 단위 이진(Binary) 입출력을 통한 효율적인 레코드 관리  
- **fgetsfputs.c**: 줄 단위 문자열 처리를 이용한 파일 복사 구현  
- **ex9-1.c**, **filequiz.c**: 파일 내 특정 데이터 검색 및 조건부 복사 알고리즘  

---

### 5) 실전 알고리즘 응용 (Algorithm Challenges)
- **2019-3.c**: `swapNodes`, `findAge`, 리스트 반전 등 여러 기능을 한 번에 다루는 종합 유형 풀이  
- **delodds** (in **reverse_sort_3.c**): 홀수 번째 인덱스 노드만 선택적으로 삭제하는 제어 로직 구현  

---

## 🚀 실행 방법 (예시)

```bash
# 컴파일
gcc save_load_1.c -o save_load_1

# 실행
./save_load_1
```

> 파일명에 맞춰 컴파일 대상(`.c`)과 실행 파일명(`-o`)만 변경하면 됩니다.
