#include <stdio.h>

int main() {
    
    int nums = 2;

    switch (nums)
    {
    case 1:
        printf("이거 안나옴");
        break;
    
    default:
        printf("이거 나옴");
        break;
    }

    return 0;
}