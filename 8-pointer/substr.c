#include <stdlib.h>
#include <stdio.h>

int main () {
    char *T = malloc(100005 * sizeof(*T));
    char *S = malloc(100005 * sizeof(*S));
    for (int i = 0; i < 100005; i++) {
        *(S + i) = ' ';
        *(T + i) = ' ';
    }
    int len_S = 0;
    int len_T = 0;
    scanf("%s", S);
    scanf("%s", T);
    for (int i = 0; i < 100005; i++) {
        if (*(S + i) == ' ') {
            len_S = i - 1;
            break;
        }
    }
    for (int i = 0; i < 100005; i++) {
        if (*(T + i) == ' ') {
            len_T = i - 1;
            break;
        }
    }

    for (int i = 0; i < len_S - len_T + 1; i++) {
        if (*(S + i) == *(T)) {
            for (int j = 1; j < len_T; j++) {
                if (j == len_T - 1 && *(S + i + j) == *(T + j)) {
                    printf("%d ", i);
                }
                else if (*(S + i + j) != *(T + j)) {
                    break;
                }
            }
        }
    }
    return 0;
}