#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main () {
    char *a = malloc(5000 * sizeof *a);
    for (int i = 0; i < 5000; i++) {
        *(a + i) = ' ';
    }
    int n = 0;
    int i = 1;
    while(*(a + i - 1) != '\n') {
        scanf("%c", a + i);
        i++;
    }
    for (int j = 1; j <= i; j++) {
        if (*(a + j - 1) == ' ') {
            *(a + j) = toupper(*(a + j));
            printf("%c", *(a + j));
        }
        else {
            *(a + j) = tolower(*(a + j));
            printf("%c", *(a + j));
        }
    }
    free(a);
}