#include <stdio.h>

int main() {
    int a[3] = {1, 2, 3};

    int a_length = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < a_length; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}