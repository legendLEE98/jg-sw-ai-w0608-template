#include <stdio.h>

void main() {
    int arr[] = {1, 2, 3};
    int *p = arr;

    int arr_length = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < arr_length; i++) {
        printf("%d\n", *(p+i));
    }
}