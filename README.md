# 자료구조 실습 (Data Structure Labs)

이 저장소는 자료구조 학습/실습을 위해 구성되었습니다. 폴더는 **assignment**(과제), **middle**(중간), **final**(기말)로 구분되어 있으며, 모든 예제는 C 언어로 작성되었습니다.

> 폴더 구조(루트 기준): `assignment/`, `middle/`, `final/`  
> 언어 비율: C 100%

---

## 📁 폴더 안내

- `assignment/` — 수업/과제용 실습 코드
- `middle/` — 중간고사 대비 연습 코드 및 예제
- `final/` — 기말고사 대비 연습 코드 및 예제

> 각 폴더에는 독립적으로 컴파일 가능한 예제들이 포함될 수 있습니다. 파일별로 `main()`이 중복될 수 있으니, **하나의 실행 파일만 빌드**하도록 유의하세요.

---

## 🚀 빠른 시작 (컴파일 & 실행)

아래 예시는 **단일 C 소스 파일**을 컴파일하는 전형적인 방법입니다. 파일명이 다를 수 있으니, `<file.c>`를 실제 파일명으로 바꿔 사용하세요.

```bash
# 1) 과제 예제 컴파일/실행
cd assignment
gcc -Wall -Wextra -O2 -std=c11 <file.c> -o app
./app

# 2) 중간 대비 예제
cd ../middle
gcc -Wall -Wextra -O2 -std=c11 <file.c> -o app
./app

# 3) 기말 대비 예제
cd ../final
gcc -Wall -Wextra -O2 -std=c11 <file.c> -o app
./app
```

### 여러 소스 파일을 함께 컴파일해야 하는 경우
여러 `.c` 파일이 하나의 실행 파일을 구성한다면:

```bash
gcc -Wall -Wextra -O2 -std=c11 file1.c file2.c -o app
```

또는 오브젝트 파일을 이용해 단계적으로 빌드할 수 있습니다.

```bash
gcc -Wall -Wextra -O2 -std=c11 -c file1.c -o file1.o
gcc -Wall -Wextra -O2 -std=c11 -c file2.c -o file2.o
gcc file1.o file2.o -o app
```

> **팁**: `-Wall -Wextra`로 경고를 적극 확인하고, `-fsanitize=address,undefined`를 옵션으로 추가하면 런타임 메모리 에러를 빠르게 잡을 수 있습니다(리눅스/클랭/신형 GCC 권장).

```bash
gcc -g -O1 -std=c11 -Wall -Wextra -fsanitize=address,undefined <file.c> -o app
./app
```

---

## 🧪 입력/출력 예시 기록 권장

- 각 프로그램의 **입력 예시**, **출력 예시**, **설명**을 파일 상단 주석 또는 `README` 하위 섹션에 정리하면 재사용/복습이 편리합니다.
- 예시:
  ```c
  // 예) 링크드 리스트 삭제
  // 입력: del 3 (3번째 노드 삭제)
  // 출력: ... (삭제 후 리스트)
  ```

---

## 🧹 코드 스타일 & 권장 사항

- **헤더 가드**: 사용자 정의 헤더(`.h`)에는 `#ifndef/#define/#endif` 사용
- **메모리 관리**: `malloc` 후 NULL 체크, 사용 완료 시 `free`
- **문자열 처리**: `scanf("%s", buf)`에는 **폭 제한**(예: `"%31s"`) 필수
- **함수 분리**: 자료구조 조작(삽입/삭제/탐색)과 입출력을 분리
- **테스트 케이스**: 경계 조건(빈 리스트, 단일 노드, 중복 키 등) 포함
- **반환값 설계**: 성공/실패를 `int`/`enum`으로 명확히 반환


---

## 📦 의존성

- 컴파일러: GCC 또는 Clang (C11 이상 권장)
- 운영체제: Linux/WSL/macOS/Windows(WSL 권장)

---

## 📝 라이선스

별도 라이선스 파일이 없으므로 **개인 학습/연습 용도**로 사용을 권장합니다. 외부 배포가 필요하면 라이선스를 명시하세요(예: MIT).

---

## 👤 Maintainer

- Owner: @byoung-woo
- Contact: 저장소 이슈 또는 PR로 소통

