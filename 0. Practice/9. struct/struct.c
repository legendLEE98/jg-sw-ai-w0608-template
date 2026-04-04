#include <stdio.h>

typedef struct Tree
{
    int value;
    struct Tree *next;
    struct Tree *prev;
} tree;

void main() {
    tree a;
    tree b;
    a.value = 1;
    b.value = 2;

    a.next = &b;  // 주소를 넣어야 함
    b.prev = &a;

    printf("%d\n", a.value);         // 1
    printf("%d\n", a.next->value);   // 2 (포인터니까 -> 사용)
}