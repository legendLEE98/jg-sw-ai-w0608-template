#include <stdio.h>

int bigNumber(int x, int y) {
    if (x > y)
        return x;
    else
        return y;
} 

int main() {

    int a = 1;
    int b = 2;

    // 함수가 아래 있어도 실행은 됨. 다만 타입이 다를 경우 깨질 가능성 있음
    // bigNumber를 명시적으로 main 상단부에 적어주거나, 함수 자체를 위로 올려야 함.
    int result = bigNumber(a, b);
    printf("큰 값 : %d", result);
}