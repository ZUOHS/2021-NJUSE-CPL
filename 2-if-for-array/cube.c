#include <stdio.h>
int main() {
    long long a = 0;
    long long c = 0;
    long long sum = 0;
    scanf("%lld", &a);
    long long b[a];
    for (long long i = a; i >= 1; i--) {
        scanf("%lld", &b[i]);
        c = i * b[i];
        sum = sum + c;
    } printf("%lld", sum);
    return 0;
}
