#include <stdio.h>
#include <math.h>

int main () {
    int i = 0;
    int n = 0;
    scanf("%d", &n);
    int a[n];
    long long int c = 1;
    long long int sum = 0;
    int b = 0;
    long long int out = 0;
    for(i = 1; i <= n; i++) {
       c = c * i;
       b = c % 10007;
       sum = sum +b;
       out = sum % 10007;
    } printf("%lld", out);


}