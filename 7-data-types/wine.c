#include <stdio.h>

int main () {
    int n = 0;
    int L = 0;
    scanf("%d%d", &n, &L);
    int money[10004];
    int amount[10004];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &money[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &amount[i]);
    }
    int mio[10004];
    int number[10004];
    for (int i = 1; i <= n; i++) {
        int max = 0;
        int count = 0;
        for (int j = 1; j <= n; j++) {
            if (money[j] > max) {
                max = money[j];
                count = j;
            }
        }
        mio[i] = max;
        number[i] = count;
        money[count] = 0;
    }
    int i = 0;
    int out = 0;
    while (L > 0) {
        i = i + 1;
        if (amount[number[i]] >= L) {
            out = out + L * mio[i];
            break;
        }
        else {
            out = out + amount[number[i]] * mio[i];
            L = L - amount[number[i]];
        }
    }
    printf("%d", out);
}