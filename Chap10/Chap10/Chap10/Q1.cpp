// Q1. Stack Unwinding 에 대해서 설명하세요.
// 함수가 함수를 호출하면 매개변수, 자동변수, 기타 추가 정보가 모두 스택 메모리에 쌓인다.
// 호출 스택은 이 정보들을 쌓여 올라간 순서를 확인해 함수 호출 관계를 확인할 수 있다.
// 함수를 반환하면 스택은 자동으로 줄어들어 함수 호출 전으로 되돌아간다.

// A가 B를 B가 C를 호출한다면, C가 가장 마지막에 호출된 함수이다.
// C에서 예외가 발생했을 때, A가 호출되기 전으로 되돌려야하는 경우가 있다.
// 이때 정상적으로는 모든 함수가 반환되어야되지만, 예외처리를 통해 반환 없이 스택을 되돌릴 수 있다.

// ExceptStack.cpp 참고