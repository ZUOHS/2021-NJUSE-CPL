#include <stdio.h>
int main () {
    int n = 0;
    char lar[100005];
    scanf("%d", &n);
    int judge[100] = {0};
    for (int l = 1; l <= n; l++) {
        judge[l] = 1;
        for (int i = 0; i <= 100000; i++) {
            lar[i] = ' ';
        }
        scanf("%s", lar);
        int r = 0;
        for (int i = 100000; i >= 1; i--) {
            if (lar[i] != ' ') {
                r = i;
                break;
            }
        }
        int a[100005] = {0};
        int position = 50000;
        int count = 0;
        for (int i = 0; i <= r; i++) {
            if (count) {
                judge[l] = 0;
                break;
            } else {
                if (lar[i] == '(') {
                    a[position] = 1;
                    position = position + 1;
                } else if (lar[i] == '[') {
                    a[position] = 2;
                    position = position + 1;
                } else if (lar[i] == '{') {
                    a[position] = 3;
                    position = position + 1;
                } else if (lar[i] == ')') {
                    if (a[position - 1] == 1) {
                        a[position - 1] = 0;
                        position = position - 1;
                    }
                    else if (a[position - 1] == 3 || a[position - 1] == 2) {
                        judge[l] = 0;
                        count = 1;
                    }
                } else if (lar[i] == ']') {
                    if (a[position - 1] == 2) {
                        a[position - 1] = 0;
                        position = position - 1;
                    }
                    else if (a[position - 1] == 3 || a[position - 1] == 1) {
                        judge[l] = 0;
                        count = 1;
                    }
                } else if (lar[i] == '}') {
                    if (a[position - 1] == 3) {
                        a[position - 1] = 0;
                        position = position - 1;
                    }
                    else if (a[position - 1] == 1 || a[position - 1] == 2) {
                        judge[l] = 0;
                        count = 1;
                    }
                } else if (lar[i] == ' ') {
                    a[position] = a[position];
                }
            }
        }
        for (int i = 1; i <= 100000; i++) {
            if (a[i] != 0) {
                judge[l] = 0;
                break;
            }
            if (i == 100000) {
                judge[l] = 1;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (judge[i]) {
            printf("True\n");
        } 
        else {
            printf("False\n");
        }
    }
}
