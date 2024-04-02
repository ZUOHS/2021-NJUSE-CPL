#include <stdio.h>
int a[100005];
int l[100005];
int r[100005];
int main () {
    int n = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        l[i] = 0;
        r[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int left = i; left > 0; left--) {
            if (a[left] > a[i]) {
                l[i] = left + 1;
                break;
            } else if (left == 1) {
                l[i] = 1;
            }
        }
        for (int right = i; right <= n; right++) {
            if (a[right] > a[i]) {
                r[i] = right - 1;
                break;
            } else if (right == n) {
                r[i] = n;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", l[i], r[i]);
    } 
    return 0;
}