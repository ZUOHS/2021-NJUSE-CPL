#include <stdio.h>
#include <math.h>

double fx(double t, int p, int m[], int n);
double Simp(double l, double r, int p, int m[], int );
double Integration(double l, double r, int p, int m[], double e, int n);


int main () {
    int n = 0;
    int p = 0;
    double e = pow(10, -5);
    scanf("%d%d", &n, &p);
    int m[n + 1];
    for (int i = 0; i <= n; i++) {
        scanf("%d", &m[i]);
    }
    double a = 0;
    double b = 0;
    scanf("%lf%lf", &a, &b);
    printf("%f", Integration(a, b, p, m, e, n));
    return 0;
}
double fx(double t, int p, int m[], int n) {
    double sum = 0;
    double temp = 0;
    for (int i = 0; i <= n; i++) {
        temp = m[i] * pow(t, i);
        sum = sum + temp;
    }
    return pow(sum, p);
}
double Simp(double l, double r, int p, int m[], int n) {
    double out = ((4 * fx((l + r) / 2.0, p, m, n) + fx(l, p, m, n) + fx(r, p, m, n)) / 6.0) * (r - l);
    return out;
}
double Integration(double l, double r, int p, int m[], double e, int n) {
    double middle = l + (r - l) / 2.0;
    double S = Simp(l, r, p, m, n);
    double SL = Simp(l, middle, p, m, n);
    double SR = Simp(middle, r, p, m, n);
    if (SL + SR - S <= 15 * e && SL + SR - S >= -15 * e) {
        return SL + SR + (SL + SR - S) / 15;
    }
    return Integration(l, middle, p, m, e / 2.0, n) + Integration(middle, r, p, m, e / 2.0, n);
}