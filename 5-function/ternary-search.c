#include <stdio.h>
#include <math.h>
int a[30];

int main () {
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i <= 25; i++) {
        a[i] = 0;
    }
    for (int i = n; i >= 0; i--) {
        a[i] = 0;
        scanf("%d", &a[i]);
    }
    double l = 0;
    double r = 0;
    double p1 = 0;
    double p2 = 0;
    scanf("%lf%lf", &l, &r);
    for (int i = 1; i <= 10000; i++) {
        p1 = l + (r - l) / 3.0;
        p2 = l + (r - l) * 2.0 / 3.0;
        double left = 0;
        for (int i = 22; i >= 0; i--) {
        double temp = 0;
        temp = a[i] * pow(p1, i);
        left = left + temp;
    }
        double right = 0;
        for (int i = 22; i >= 0; i--) {
        double temp = 0;
        temp = a[i] * pow(p2, i);
        right = right + temp;
    }
        if (left >= right) {
            r = p2;
        } else {
            l = p1;
        }
    }
    printf("%lf", p1);
    return 0;
}
