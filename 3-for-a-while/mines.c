#include <stdio.h>

int main () {
    int n = 0;
    scanf ("%d", &n);
    int board[n + 2][n + 2];
    int count[n + 2][n + 2];
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < n + 2; j++) {
            board[i][j] = 0;
            count[i][j] = 0;
        }
    }
    for (int m = 1; m <= n; m++) {
        char a[n + 1];
        scanf("%s", a);
        for (int i = 1; i <= n; i++) {
            if (a[i - 1] == '*') {
                board[m][i] = 1;
            } else {
                board[m][i] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i][j] == 0) {
                count[i][j] = board[i - 1][j] + board[i - 1][j - 1] + board[i - 1][j + 1]
                + board[i + 1][j] + board[i + 1][j - 1] + board[i + 1][j + 1]
                + board[i][j - 1] + board[i][j + 1];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i][j] == 1) {
                printf("*");
            }
            else {
                printf("%d", count[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}