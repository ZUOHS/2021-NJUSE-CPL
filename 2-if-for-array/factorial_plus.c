#include <stdio.h>
#include <math.h>

int main () {
    long long int i = 0;
    long long int n = 0;
    scanf("%lld", &n);
    int a[n];
    long long int c = 1;
    long long int sum = 0;
    int b = 0;
    long long int out = 0;
    for(i = 1; i <= n; i++) {
       c = c * i;
       b = c % 1000000007;
       sum = sum +b;
       out = sum % 1000000007;
    } printf("%lld", out);


}