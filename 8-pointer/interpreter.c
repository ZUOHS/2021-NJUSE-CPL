#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main () {
    int n = 0;
    scanf("%x", &n);
    void *m = &n;
    int *a = m;
    unsigned int *b = m;
    float *c = m;
    printf("%d\n", *a);
    printf("%u\n", *b);
    printf("%.6f", *c);
}