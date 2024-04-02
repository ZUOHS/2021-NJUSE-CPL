#include <stdio.h>

int a[100005];
int Source(int m);
int main () {
    int n = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        a[i] = 0;
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", Source(i));
    }
    return 0;
}

int Source(int m) {
    if (a[m] == m) {
        return a[m];
    }
    return a[a[m]];
}