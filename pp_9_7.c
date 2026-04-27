#include <stdio.h>

int square (int x){
    return x * x;
}

int power(int x, int n){
    if (n == 0) return 1;
    if (n == 1) return x; 
    if(n % 2 == 0) return square(power(x , n/2));
    else return x * power(x, n-1);
}

int main(){
    int x, n;
    printf("Enter numbers to calculate power:");
    scanf("%d %d", &x, &n);
    printf("Power is %d", power(x, n));
    return 0;
}