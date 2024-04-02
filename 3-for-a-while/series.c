#include <stdio.h>
#include <math.h>

int main () {
    int n = 0;
    int x = 0;
    scanf("%d", &n);
    scanf("%d", &x);
    double tx = 1.0;
    double sum = 1.0;
    for (int i = 1; i <= n; i++) {
        double count = 1.0;
        for (int j = 1; j <= i; j++) {
            count = count * j;
        }
        tx = pow(x, i);
        sum = sum + tx / count;
    }
    printf("%.3f", sum);
    return 0;
}