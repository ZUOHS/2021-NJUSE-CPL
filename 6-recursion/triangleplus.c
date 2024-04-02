#include <stdio.h>
#include <math.h>

void Triangle(int b);

int main () {
    
    int n = 0;
    scanf("%d", &n);
    for (int i = 1; i <= pow(2, n); i++) {
        if (i % 2) {
            for (int j = 1; j <= pow(2, n) - i; j++) {
                printf(" ");
            }
        } else if (!(i % 2)) {
            for (int j = 1; j <= pow(2, n) - i; j++) {
                printf(" ");
            }
        }
        Triangle(i);
        printf("\n");
    }
    return 0;
}
void Triangle(int b) {
    if (b == 1) {
        printf("/\\");
    } else if (b == 2) {
        printf("/__\\");
    } else {
        int c = 1;
        int count = 0;
        for (int m = 1; m < 10000; m++) {
            c = pow(2, m);
            if (c >= b) {
                count = m - 1;
                break;
            }
        }
        Triangle(b - pow(2, count));
        for (int j = 1; j <= ((int)pow(2, count + 1) - b) * 2; j++) {
            printf(" ");
        }
        Triangle(b - pow(2, count));
    }
}