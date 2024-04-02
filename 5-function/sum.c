#include <stdio.h>
#include <math.h>
int main () {
    int n = 0;
    int t = 0;
    scanf("%d", &n);
    scanf("%d", &t);
    int sum = 0;
    for (int i = 0;  i < n; i++) {
        int temp = 0;
        temp = pow(10, i) * t * (n - i);
        sum = sum + temp;
    }
    printf("%d", sum);
    return 0;
}