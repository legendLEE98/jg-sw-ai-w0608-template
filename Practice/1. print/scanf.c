#include <stdio.h>

int main(){

    int num1;
    int num2;

    // 입력 받을 땐, &이 반드시 필요함.
    // scanf로 입력받은 값을 어디에 저장해야할지 모름.
    printf("input 받기 1 \n");
    scanf("%d", &num1);
    printf("input 받기 2 \n");
    scanf("%d", &num2);

    printf("%d\n%d\n", num1, num2);
    return 0;
}