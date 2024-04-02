#include <stdio.h>
#include <math.h>

int main() {
   int a = 0;
   int b = 0;
   char c = 'i';
   char d = 'j';
    while (scanf("%d%s%s%d", &a, &c, &d, &b) != EOF) {
        if (c == '+') {
            printf("%d\n", a + b);
        }
        else if (c == '-') {
            printf("%d\n", a - b);
        }
        else if (c == '*' && d != '*') {
            printf("%d\n", a * b);
        }
        else if (c == '/' && d != '*') {
            printf("%d\n", a / b);
        }
        else if (c == '%') {  
            printf("%d\n", a % b);
        }
        else if (c == '/' && d == '*') {
            printf("%.3f\n", (a * 1.0) / (b * 1.0));
        }
        else if (c == '*' && d == '*') {
            printf("%d\n", floor(pow(a, b)));
        }
    }
    
   return 0;
}