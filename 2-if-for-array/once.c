#include <stdio.h>
int main() {
    int count = 0;
    scanf("%d", &count);
    int i = 0;
    int n = 2 * count - 1;
    int a[n];
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 1; i <= n; i++) {
        int count1 = 0;
        for (int j = 1; j <= n; j++) {
            if (a[j] == a[i]) {
            count1++;}
        }  if (count1 == 1) {
            printf("%d", a[i]);
            break;
        }
    }
    
    
    return 0;
}
