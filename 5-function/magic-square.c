#include <stdio.h>
#include <math.h>
int board[1000][1000];
int RightUp(int a, int b, int n);

int main () {
    int n = 0;
    scanf("%d", &n);
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            board[i][j] = 0;
        }
    }
    int a = n /2 + 1;
    int b = 1;
    board[b][a] = 1;
    for (int i = 2; i <= n * n; i++) {
        if (RightUp(a, b, n)) {
            if (a < n) {
                a = a + 1;
            } else {
                a = 1;
            }
            if (b > 1) {
                b--;
            }
            else {
                b = n;
            }
            board[b][a] = i;
        } else {
            if (b == n) {
                b = 1;
            } else {
                b++;
            }
            board[b][a] = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", board[j][i]);
        }
        printf("\n");
    }

    return 0;
}
int RightUp(int a, int b, int n) {
    int c = 0;
    int d = 0;
    if (a < n) {
        c = a + 1;
    } else {
        c = 1;
    }
    if (b > 1) {
        d = b-1;
    } else {
        d = n;
    }
    if (board[d][c] == 0) {
        return 1;
    }
    return 0;
}