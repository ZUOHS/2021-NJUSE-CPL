#include <stdio.h>
#include <math.h>

int main() {
   int a = 0;
   int b = 0;
   int i = 0;
   char op[3];
    while (scanf("%d %s %d", &a, op, &b) != EOF ) {
        if (op[0] == '+') {
            printf("%d\n",a + b);
        } else if (op[0] == '-') {
            printf("%d\n", a - b);
        } else if (op[0] == '*' ) {
            if (op[1] == '*') {
                printf("%d\n", (int)pow(a, b));
            } else printf("%d\n", a * b);
        } else if (op[0] == '/') {
            if (op[1] == '*') {
                printf("%.3f\n", (a * 1.0) / (b * 1.0));
            } else {
                printf("%d\n",a / b);
            }
        } else if (op[0] == '%') {  
            printf("%d\n", a % b);
        }
    }
    
   
   return 0;
}