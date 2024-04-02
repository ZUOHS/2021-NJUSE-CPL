#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Swap(char *a);

int main () {
    char *a = malloc(10000 * sizeof (char));
    char *b = malloc(2 * sizeof (char));
    char *c = malloc(10000 * sizeof (char));
    for (int j = 0; j < 10000; j++) {
        *(a + j) = ' ';
        *(c + j) = ' ';
    }
    scanf("%s%s", a, b);
    int i = 0;
    int k = 0;
    for (int j = 0; j < 10000; j++) {
        if (*(a + j) == ' ') {
            break;
        } else if (*(a + j) != *b) {
            *(c + 100 * i + k) = *(a + j);
        } else if (*(a + j) == *b) {
            i = i + 1;
            k = -1;
        }
        k = k + 1;
    }
    
    for (int j = 0; j < i; j++) {
        for (int l = 0; l < i; l++) {
            if (strcmp((c + l * 100), (c + l * 100 + 100)) > 0) {
                Swap((c + l * 100));
            }
        }
    }

    for (int j = 0; j <= i; j++) {
        for (int l = 0; l < 100; l++) {
            if (*(c + j * 100 + l) == ' ') {
                break;
            }
            else {
                printf("%c", *(c + j * 100 + l));
            }
        }
        printf("\n");
    }
}

void Swap(char *a) {
    for (int i = 0; i < 100; i++) {
        char temp = *(a + i);
        *(a + i) = *(a + i + 100);
        *(a + i + 100) = temp;
    }
}