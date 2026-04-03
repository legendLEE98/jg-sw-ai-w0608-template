#include <stdio.h>

int main() {
    // %d : int형 (음수 표현 가능)
    // %u : unsigned int형 (음수 표현 불가)
    // %f : float형
    // %c : char형 (아스키 문자열)
    // %hhu : char형 (출력)

    printf("%d / %u / %f / %c / %hhu \n", -10, -10, 3.14, 97, 30);
    return 0;
}