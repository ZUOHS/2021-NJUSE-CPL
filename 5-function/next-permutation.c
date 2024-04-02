#include <stdio.h>

int main () {
    int n = 0;
    scanf("%d", &n);
    int a[3000] = {0};
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    a[n + 1] = 0;
    int m = 0;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        int judge = 1;
        for (int j = i; j <= n; j++) {
            if (a[j] < a[j + 1]) {
                judge = 0;
                break;
            }
        }
        if (judge) {
            for (int k = i; k <= n + 1; k++) {
                if (a[k] < a[i - 1]) {
                    int temp = a[k - 1];
                    a[k - 1] = a[i - 1];
                    a[i - 1] = temp;
                    m = n - i + 1;
                    count = 1;
                    break;
                }
            }
        }
        if (count) {
            break;
        }
    }
    for (int i = 1; i <= m / 2; i++) {
        int temp_three = a[n - i + 1];
        a[n - i + 1] = a[n - m + i];
        a[n - m + i] = temp_three;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}