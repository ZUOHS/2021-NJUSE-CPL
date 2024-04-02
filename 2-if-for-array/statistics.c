#include <stdio.h>

int main () {
    int n = 0;
    scanf("%d", &n);
    int what_char = 0;;
    int count[26];
    int max = 0;
    for (int i = 1; i <= 26; i++) {
        count[i] = 0;
    }
    for (int i = 0; i <= n; i++) {
        scanf("%c", &what_char);
        count[what_char - 96]++;
    }
    
    max = count[1];
    for (int i = 1; i <= 26; i++) {
        
        if (count[i] >= max) {
            max = count[i];
        }
    }
   
    for (int i = max; i >= 1; i--) {
        for (int j = 1; j <= 26; j++) {
            if (count[j] >= i) {
                printf(" = ");
            } else {
                printf("   ");
            }
        }

        printf("\n");
    }
    printf("------------------------------------------------------------------------------\n");
    printf(" a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z");
    return 0;
}