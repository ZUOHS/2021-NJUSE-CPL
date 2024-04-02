#include <stdio.h>

int main () {
    int n = 0;
    scanf("%d", &n);
    char a[10004];
    for (int i = 0; i <= 10000; i++) {
        a[i] = '*';
    }
    int position = 10000;
    int judge = 0;
    for (int i = 1; i <= n; i++) {
        char op[8];
        scanf("%s", op);
        if (judge) {
            a[position] = op[0];
            position = position - 1;
            judge = 0;
            i = i - 1;
        }
        else {
            if (op[2] == 's') {
                judge = 1;
            }
            else if (op[0] == 'p' && op[1] == 'o') {
                if (position == 10000) {
                    printf("Empty\n");
                } else {
                    a[position + 1] = '*';
                    position = position + 1;
                }
            }
            else if (op[0] == 't') {
                if (position == 10000) {
                    printf("Empty\n");
                }
                else {
                    printf("%c\n", a[position + 1]);
                }
            }
            else if (op[1] == 'r') {
                if (position == 10000) {
                    printf("Empty\n");
                }
                else {
                    for (int j = position + 1; j <= 10000; j++) {
                        printf("| %c |\n", a[j]);
                    }
                    printf("|===|\n");
                }
            }
        }
    }
    return 0;
}