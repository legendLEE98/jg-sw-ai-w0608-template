#include <stdio.h>

int main() {
    int i = 0;
    int j = 0;    
    int num = 3;

    while (i < num) {
        printf("실행 \n");
        i++;
    }
    
    // do while일 땐 한번은 실행은 함.
    do {
        printf("실행\n");
        j++;
    } while (j > num);
}