#include <stdio.h>
#include <stdlib.h>

void main() {
    int *a = malloc(sizeof(int) * 100);

    // malloc으로 선언한 사이즈는 볼 수 없음
    // 그래서 따로 변수를 들고 다녀야 함. n = 100 이런식으로
    // 아래와 같은 경우는, *a가 sizeof(int) 형처럼 이해함.
    printf("%d\n\n", sizeof(*a));
    *(a+0) = 10;

    printf("%d", a[0]);
}