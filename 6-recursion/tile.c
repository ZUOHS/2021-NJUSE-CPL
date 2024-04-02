#include <stdio.h>
int Tile(int a);

int main () {
    int n = 0;
    scanf("%d", &n);
    printf("%d", Tile(n));
    return 0;
}
int Tile(int a) {
    if (a == 1) {
        return 1;
    }
    if (a == 2) {
        return 2;
    }
    return (Tile(a - 1) + Tile(a - 2));
}