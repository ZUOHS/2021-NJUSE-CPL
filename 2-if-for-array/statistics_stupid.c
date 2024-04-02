#include <stdio.h>

int main () {
    int n = 0;
    scanf("%d", &n);
    char what_char[100];
    int count[26];
    int max = 0;
    scanf("%s", what_char);
    for (int i = 1; i <= 26; i++) {
        count[i] = 0;
    }
    for (int i = 0; i <= n; i++) {
        if (what_char[i] == 'a') {
            count[1]++;
        } else if (what_char[i] == 'b') {
            count[2]++;
        } else if (what_char[i] == 'c') {
            count[3]++;
        } else if (what_char[i] == 'd') {
            count[4]++;
        } else if (what_char[i] == 'e') {
            count[5]++;
        } else if (what_char[i] == 'f') {
            count[6]++;
        } else if (what_char[i] == 'g') {
            count[7]++;
        } else if (what_char[i] == 'h') {
            count[8]++;
        } else if (what_char[i] == 'i') {
            count[9]++;
        } else if (what_char[i] == 'j') {
            count[10]++;
        } else if (what_char[i] == 'k') {
            count[11]++;
        } else if (what_char[i] == 'l') {
            count[12]++;
        } else if (what_char[i] == 'm') {
            count[13]++;
        } else if (what_char[i] == 'n') {
            count[14]++;
        } else if (what_char[i] == 'o') {
            count[15]++;
        } else if (what_char[i] == 'p') {
            count[16]++;
        } else if (what_char[i] == 'q') {
            count[17]++;
        } else if (what_char[i] == 'r') {
            count[18]++;
        } else if (what_char[i] == 's') {
            count[19]++;
        } else if (what_char[i] == 't') {
            count[20]++;
        } else if (what_char[i] == 'u') {
            count[21]++;
        } else if (what_char[i] == 'v') {
            count[22]++;
        } else if (what_char[i] == 'w') {
            count[23]++;
        } else if (what_char[i] == 'x') {
            count[24]++;
        } else if (what_char[i] == 'y') {
            count[25]++;
        } else if (what_char[i] == 'z') {
            count[26]++;
        } 
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