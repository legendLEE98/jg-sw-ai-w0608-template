#include <stdio.h>
#include <stdlib.h>

void main() {
    int *a = malloc(sizeof(int));

    *a = 42;
    
    printf("%d\n", *a);
    free(a);
    
    int *b = malloc(sizeof(int));
    printf("%d\n", *b);
    printf("%p\n", b);
    free(b);
}