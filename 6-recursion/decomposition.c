#include <stdio.h>

void ToPrint (int n, int i);

int SumWays(int n, int nums);

int a[30][20];
int main () {
    for (int i = 1; i <= 30; i++) {
        for (int j = 1; j <= 30; j++) {
            if (i == j) {
                a[i][j] = 1;
            }
            else {
                a[i][j] = SumWays(i, j);
            }
        }
    }
    int n = 0;
    scanf("%d", &n);
    for (int i = 1; i <= SumWays(n, 1); i++) {
        ToPrint(n, i);
        printf("\n");
    }
    return 0;
} 
int SumWays(int n, int nums) {
    if (n == 1) {
        return 1;
    } 
    if (n == nums) {
        return 1;
    }
    int out = 0;
    for (int i = nums; i <= n / 2; i++) {
        out += SumWays(n - i, i);
    }
    return out + 1;
}

void ToPrint (int n, int i) {
    if (n == 1) {
        printf("1 ");
    } else if (i == a[n][1]) {
        printf("%d", n);
    } else {
        int start = 0;
        for (int j = 2; j <= (n / 2 + 1); j++) {
            if ((a[n][1] - a[n][j]) >= i) {
                start = j - 1;
                break;
            }
        }
        int position = i - a[n][1] + a[n][start] + a[n - start][1] - a[n - start][start];
        printf("%d ", start);
        ToPrint (n - start, position);
    }
}