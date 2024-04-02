#include <stdio.h>

int main () {
    int n = 0;
    int m = 0;
    scanf("%d%d", &n, &m);
    int a[m + 2][n + 2];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[j][i]);
        }
    }
    int maxm[1003];
    int max = 0;
    for (int j = 1; j <= m; j++) {
        max = 0;
        for (int i = 1; i <= n; i++) {
            if (a[j][i] > max) {
                max = a[j][i];
            }
        }
        maxm[j] = max;
    }
    for (int j = 1; j <= m; j++) {
        if (maxm[j] > max) {
            max = maxm[j];
        }
    }
    for (int i = 1; i <= max; i++) {
        for (int j = 1; j <= m; j++) {
            if (maxm[j] + i - 1 >= max) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
    max = 0;
    int maxn[1003];
    for (int i = 1; i <= n; i++) {
        max = 0;
        for (int j = 1; j <= m; j++) {
            if (a[j][i] > max) {
                max = a[j][i];
            }
        }
        maxn[i] = max;
    }
    for (int i = 1; i <= n; i++) {
        if (maxn[i] > max) {
            max = maxn[i];
        }
    }
    for (int j = 1; j <= max; j++) {
        for (int i = 1; i <= n; i++) {
            if (maxn[i] + j - 1 >= max) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}