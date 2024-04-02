#include <stdio.h>

int Pour(int k, int Va, int Vb, int Vc, int a, int b, int c, int a0, int b0, int c0);
int main () {
    int k = 0;
    int Va = 0;
    int Vb = 0;
    int Vc = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int a0 = 0;
    int b0 = 0;
    int c0 = 0;
    scanf("%d%d%d%d%d%d%d%d%d%d", &k, &Va, &Vb, &Vc, &a, &b, &c, &a0, &b0, &c0);
    if (Pour(k, Va, Vb, Vc, a, b, c, a0, b0, c0)) {
        printf("Yes");
    } else {
        printf("No");
    }
}

int Pour(int k, int Va, int Vb, int Vc, int a, int b, int c, int a0, int b0, int c0) {
    if (a == a0 && b == b0 && c == c0) {
        return 1;
    }
    if (k <= 0) {
        return 0;
    }
    //pour a to b;
    int aab = 0;
    int bab = 0;
    if (a + b > Vb) {
        bab = Vb;
    } else {
        bab = a + b;
    }
    //pour a to c
    int aac = 0;
    int cac = 0;
    if (a + c > Vc) {
        cac = Vc;
    } else {
        cac = a + c;
    }
    //pour b to a
    int bba = 0;
    int aba = 0;
    if (a + b > Va) {
        aba = Va;
    } else {
        aba = a + b;
    }
    //pour b to c
    int bbc = 0;
    int cbc = 0;
    if (c + b > Vc) {
        cbc = Vc;
    } else {
        cbc = c + b;
    }
    //pour c to a
    int cca = 0;
    int aca = 0;
    if (c + a > Va) {
        aca = Va;
    } else {
        aca = c + a;
    }
    //pour c to b
    int ccb = 0;
    int bcb = 0;
    if (c + b > Vb) {
        bcb = Vb;
    } else {
        bcb = b + c;
    }
    return (Pour(k - 1, Va, Vb, Vc, aab, bab, c, a0, b0, c0) || 
    Pour(k - 1, Va, Vb, Vc, aac, b, cac, a0, b0, c0) ||
    Pour(k - 1, Va, Vb, Vc, aba, bba, c, a0, b0, c0) ||
    Pour(k - 1, Va, Vb, Vc, a, bbc, cbc, a0, b0, c0) ||
    Pour(k - 1, Va, Vb, Vc, aca, b, cca, a0, b0, c0) ||
    Pour(k - 1, Va, Vb, Vc, a, bcb, ccb, a0, b0, c0) );
}