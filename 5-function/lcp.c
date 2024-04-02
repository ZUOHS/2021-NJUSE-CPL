#include <stdio.h>
#include <math.h>
#define SIZE 1000

int main () {
    int m = 0;
    int n = 0;
    scanf("%d%d", &m, &n);
    char ant[SIZE][SIZE];
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - 1; j++) {
            ant[i][j] = '&';
        }
    }
    for (int i = 1; i <= m; i++) {
        scanf("%s", ant[i]);
    }
    int a[SIZE] = {0};
    for (int i = 1; i <= 2 * n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 0; j < SIZE; j++) {
            if (ant[a[2 * i - 1]][j] == '&' && ant[a[2 * i]][j] == '&') {
                printf("%d\n", count - 1);
                break;
            }
            else if (ant[a[2 * i - 1]][j] == ant[a[2 * i]][j]) {
                count++;
            } else {
                printf("%d\n", count);
                break;
            }
        }
    }
    return 0;
}