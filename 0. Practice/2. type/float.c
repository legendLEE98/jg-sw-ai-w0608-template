#include <stdio.h>

int main() {
    float pi = 3.14;
    const float PI = 3.141592;

    // PI = 3.1 << ERROR!
    printf("%.2f \n", pi);

    return 0;
}