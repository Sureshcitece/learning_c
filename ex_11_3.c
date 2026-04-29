#include <stdio.h>

void avg_sum(double a[], int n, double *avg, double *sum){
    int i;
    *sum = 0.0;
    for(i = 0; i < n; i++)
        *sum += a[i];
    *avg = (*sum) / n;
}

int main(){
    double *avg_p, *sum_p;
    double avg, sum;
    avg_p = &avg;
    sum_p = &sum;
    double a[] = {1.1, 2.5, 3.2, 4.9, 5.0};
    avg_sum(a, 5, avg_p, sum_p);
    printf("%f %f", avg, sum);

}