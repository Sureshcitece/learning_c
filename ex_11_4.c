#include <stdio.h>

void swap(int *p, int *q){
    int temp;
    temp = *p;
    *p = q;
} 

int main() {
    int x = 1, y= 2;
    printf("Before swap: %d %d\n", x, y);
    swap(&x, &y);
    printf("After swap: %d %d\n", x, y);
}