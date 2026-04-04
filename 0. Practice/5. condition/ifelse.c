#include <stdio.h>

int main() {
    int nums = 5;
    if (nums < 3) {
        printf("이건 안나옴");
    } else if (nums == 5){
        printf("이게 5인 조건 \n");
    } 
    else {
        printf("이게 나옴 \n");
    }
}