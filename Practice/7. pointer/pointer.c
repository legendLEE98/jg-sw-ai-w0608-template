#include <stdio.h>


// change 함수는 x의 주소값을 받음.
// 전달 받은 값 0x7fffffffddd4
int change(int *x) {
    // 해당 값을 100으로 변경함
    // 해당 주소의 값을 100으로 바꿨음
    return *x = 100;
}

int main() {
    // 앰퍼샌드(&)는 변수의 주소
    // *는 해당 주소의 값
    int a = 10;

    // change 함수에 a의 주소를 넘겨줬음

    change(&a);

    printf("%d \n", a);
    printf("%p \n", &a);
}