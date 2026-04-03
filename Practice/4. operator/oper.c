#include <stdio.h>

int main() {
    // 삼항 연산자
    // 조건이 맞으면 밸류1 : 조건이 틀리면 밸류2

    int num1 = 10;
    int num2 = 20;

    // 이 경우 오답이니 0을 반환
    // if / else문 대신 사용 가능한 문법으로 생각하면 된다고 함.
    char result = (num1 > num2) ? 1 : 0;
    
    printf("%d \n\n\n", result);
}