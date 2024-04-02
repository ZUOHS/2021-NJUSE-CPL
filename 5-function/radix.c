#include <stdio.h>
#include <math.h>

int main () {
    int p = 0;
    int q = 0;
    int r = 0;
    scanf("%d%d%d", &p, &q, &r);
    int leftp = p / 10;
    int rightp = p % 10;
    int leftq = q / 10;
    int rightq = q % 10;
    int leftr = r / 10;
    int rightr = r % 10;
    int judge = 1;
    for (int i = 2; i <= 40; i++) {
        if ((leftp * i + rightp) * (leftq * i + rightq) == (leftr * i + rightr) && i > rightr && i > rightq && i > rightp) {
            printf("%d", i);
            judge = 0;
            break;
        }
    }
    if (judge) {
        printf("0");
    }
    return 0;
}