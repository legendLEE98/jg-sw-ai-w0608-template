#include <stdio.h>

int main() {
    // 언제 쓰냐
    // 전달값을 제한하기 위해서,
    // 먼저 선언한 메모리 주소에 값을 채워넣기 위해서
    int arr[] = {1, 2, 3};
    int *p = arr;

    int arr_length = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < arr_length; i++) {
        printf("i의 값 = %d\narr[i]의 값 : %d\n\n", i, arr[i]);
    }

    return 0;
}