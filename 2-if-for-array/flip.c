#include <stdio.h>

int main () {
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    int a = 0;
    for (i = 1; i <= n; i++) {
        int j = 0;
        int b = 0;
        int count = 0;
        for (j = 1; j <= n; j++) {
            b = i % j;
            if (b == 0) {
                count++;
            } 
        }
           if ((count % 2) != 0) {
                 printf("%d ", i);
            }
        
    }
  }
