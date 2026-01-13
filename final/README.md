### 4. 💾 final/README.md
자료구조(연결 리스트)와 파일 처리(기말고사 범위)를 다룹니다.

# 🔗 Data Structures & File I/O (Final Term)

동적 할당(`malloc`)을 이용한 **연결 리스트(Linked List)** 의 구현과 데이터의 영구 저장을 위한 **파일 입출력**을 중점적으로 다룹니다.

## 📚 핵심 구현 내용

### 1. 연결 리스트 (Linked List)
단일 및 이중 연결 리스트(Doubly Linked List)를 활용하여 데이터를 관리합니다.
*(`final/linked_list/` 폴더 내)*

- **CRUD 구현**:
  - `add.c`, `first_add.c`: 노드 추가 (리스트의 끝 또는 처음에 추가).
  - `delete.c`: 특정 이름을 가진 노드 검색 및 삭제 (메모리 해제 `free` 포함).
  - `scan_add_delete_*.c`: 사용자 입력을 받아 리스트를 동적으로 관리하는 통합 프로그램.
- **고급 기능**:
  - `reverse_sort_*.c`: 리스트의 순서를 뒤집거나(`Reverse`), 나이 순으로 정렬(`Sort`)하는 알고리즘.
  - **이중 연결 리스트**: `next`뿐만 아니라 `prev` 포인터를 사용하여 양방향 탐색이 가능하도록 구현.

### 2. 파일 입출력 및 데이터 보존 (File Persistence)
구조체 데이터를 파일에 저장하고 다시 불러오는 기능을 구현합니다.
*(`final/file/` 및 `linked_list/save_load_*.c`)*

- **`save_load_*.c`**: 연결 리스트의 데이터를 파일로 저장(`save`)하고, 프로그램 재시작 시 파일에서 읽어와 리스트를 복원(`load`).
- **Standard I/O**:
  - `fprintf`, `fscanf`: 서식화된 데이터 입출력.
  - `fgets`, `fputs`: 줄 단위 입출력.
  - `fread`, `fwrite`: 바이너리 단위 구조체 입출력.
  - `filequiz.c`: 파일 복사 및 내용 처리 예제.