#include <stdio.h>

int YangHui(int a, int b);
int main () {
    int a = 0;
    int b = 0;
    scanf("%d%d", &a, &b);
    printf("%d", YangHui(a, b));
    return 0;
}
int YangHui(int a, int b) {
    if (b == 1 || a == b) {
        return 1;
    }
    return (YangHui(a - 1, b - 1) + YangHui(a - 1, b));
}