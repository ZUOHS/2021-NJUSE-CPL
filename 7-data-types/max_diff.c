#include <stdio.h>
#include <math.h>

int Max(int l, int r, int a[]);

int main () {
    int count = 0;
    int a[104];
    int i = 1;
    while (scanf("%d", &a[i]) != EOF) {
        i = i + 1;
    }
    int max = 0;
    for (int j = 1; j <= i - 1; j++) {
        int diff = abs(Max(1, j, a) - Max(j, i - 1, a));
        if (diff > max) {
            max = diff;
        }
    }
    printf("%d", max);
    return 0;
}

int Max(int l, int r, int a[]) {
    int max = 0;
    for (int i = l; i <= r; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}