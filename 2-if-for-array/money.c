#include <stdio.h>
int main() {
    int u = 0;
    int j = 0;
    int b = 0;
    int w = 0;
    scanf("%d", &u);
    for (int count = 1; count <= u; count++) {
        scanf("%d", &j);
        int a[count];
        scanf("%d", &a[count]);
        if (j ==1 ) {
            b = b + a[count];
        } else {
            w = w + a[count];
        }
    } int out = w - b;
    printf("%d", out);
    return 0;
}
