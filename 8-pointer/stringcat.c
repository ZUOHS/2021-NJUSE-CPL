#include <stdio.h>
#include <stdlib.h>
void mystrcat(char *a, char *b);

int main () {
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char *a = malloc(1003 * sizeof(*a));
        char *b = malloc(1003 * sizeof(*b));
        for (int i = 0; i < 1000; i++) {
            *(a + i) = ' ';
            *(b + i) = ' ';
        }
        scanf("%s", a);
        scanf("%s", b);
        mystrcat(a, b);
        int lena = 0;
        int lenb = 0;
        for (int i = 0; i < 1003; i++) {
            if (*(a + i) == '\0') {
                lena = i;
                break;
            }
        }
        for (int i = 0; i < 1003; i++) {
            if (*(b + i) == '\0') {
                lenb = i;
                break;
            }
        }
        for (int i = 0; i <= lena + lenb; i++) {
            printf("%c", *(a + i));
        }
        // printf("%s\n", a);
    }
}

void mystrcat(char *a, char *b) {
    int lena = 0;
    int lenb = 0;
    for (int i = 0; i < 1003; i++) {
        if (*(a + i) == '\0') {
            lena = i;
            break;
        }
    }
    for (int i = 0; i < 1003; i++) {
        if (*(b + i) == '\0') {
            lenb = i;
            break;
        }
    }
    for (int i = 0; i < lena; i++) {
        int basetwo = 0;
        if (*(a + i) == *(b)) {
            for (int j = i; j < lena; j++) {
                if (j == lena - 1 && *(a + j) == *(b + j - i)) {
                    basetwo = j - i + 1;
                }
                else if (*(a + j) != *(b + j - i)) {
                    break;
                }
            }
            if (basetwo != 0) {
                for (int k = 0; k < lenb - basetwo; k++) {
                    *(a + lena + k) = *(b + basetwo + k);
                }
                break;
            }
        }
    }
}