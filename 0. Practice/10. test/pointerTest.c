#include <stdio.h>

void main() {
    int a = 10;
    int *b = &a;

    // 포인터로 선언된 애는 포인터로 접근해야 볼 수 있음.
    printf("%d\n", *b);
}