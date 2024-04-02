#include <stdio.h>
#include <math.h>

double fx(double t);
double Simp(double l, double r);
double Integration(double l, double r);
int m[100] = {0};
int n = 0;
int p = 0;
int main () {
    scanf("%d%d", &n, &p);
    for (int i = 0; i <= n; i++) {
        scanf("%d", &m[i]);
    }
    double a = 0;
    double b = 0;
    scanf("%lf%lf", &a, &b);
    printf("%lf", Integration(a, b));
    return 0;
}
double fx(double t) {
    double sum = 0;
    double temp = 0;
    for (int i = 0; i <= n; i++) {
        temp = m[i] * pow(t, i);
        sum = sum + temp;
    }
    return pow(sum, p);
}
double Simp(double l, double r) {
    double out = ((4 * fx((l + r) / 2.0) + fx(l) + fx(r)) / 6.0) * (r - l);
    return out;
}
double Integration(double l, double r) {
    double middle = l + (r - l) / 2.0;
    if ((fabs(Simp(l, middle) + Simp(middle, r) - Simp(l, r)) < 15 * 1e-5)) {
        return Simp(l, middle) + Simp(middle, r) + (Simp(l, middle) + Simp(middle, r) - Simp(l, r)) / 15.0;
    }
    return Integration(l, middle) + Integration(middle, r);
}