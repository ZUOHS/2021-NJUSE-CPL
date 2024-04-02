#include <stdio.h>

int main () {
    int n = 0;
    scanf("%d", &n);
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        a[i] = 0;
        scanf("%d", &a[i]);
    }
    for (int j = 1; j <= n; j++) {
        int temp = 0;
        for (int i = 1; i <= j; i++) {
            for (int m = i; m <= j; m++) {
                if (a[m] < a[i]) {
                    temp = a[m];
                    a[m] = a[i];
                    a[i] = temp;
                }
            }
        }
        for (int k = 1; k <= j; k++) {
                printf("%d ", a[k]);
        }
        printf("\n");
    }
    
    return 0;
}