#include <stdio.h>
#include <stdlib.h>

void Pour(int *a, int *b);
void Print(int *a);

int n = 0;
int m = 0;
int main () {
    scanf("%d%d", &n, &m);
    int **x = malloc((n + 5) * sizeof(*x));
    for (int i = 0; i < n; i++) {
        *(x + i) = malloc((n + 5) * sizeof(int));
        (**(x + i)) = i + 1;
        *(*(x + i) + 1) = 0;
    }
    for (int i = 0; i < m; i++) {
        int a = 0;
        int b = 0;
        scanf("%d%d", &a, &b);
        Pour(*(x + a - 1), *(x + b - 1));
    }
    for (int i = 0; i < n; i++) {
        Print(*(x + i));
    }
}

void Pour(int *a, int *b) {
    if (*a == 0) {
        return;
    }
    int i = 0;
    int j = 0;
    for (i = 0; i < n; i++) {
        if (*(a + i) == 0) {
            break;
        }
    }
    for (j = 0; j < n; j++) {
        if (*(b + j) == 0) {
            break;
        }
    }
    for (int k = 0; k < i; k++) {
        *(b + j + k) = *(a + i - k - 1);
        *(a + i - k - 1) = 0;
    }
    *(b + j + i) = 0;
}

void Print(int *a) {
    if (*a == 0) {
        printf("0");
    } else {
        for (int i = 0; i < n; i++) {
            if (*(a + i) == 0) {
                break;
            } 
            printf("%d ", *(a + i));
        }
    }
    printf("\n");
}