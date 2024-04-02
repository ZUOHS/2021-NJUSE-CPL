#include <stdio.h>
#include <math.h>

int IsPrime (int number);

int Swap (int a);

int main () {
    int n = 0;
    scanf("%d", &n);
    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (IsPrime(i)) {
            if (IsPrime(Swap(i))){
                count++;
            }
        }
    }
    printf("%d", count);
    return 0;
}

int IsPrime (int number) {
    for (int j = 2; j <= sqrt(number + 1); j++) {
      if (number % j == 0) {
        return 0;
      }
    }
    return 1;
}

int Swap (int a) {
    int j = a;
    int count = 0;
    int sum = 0;
    while (j != 0) {
        count = j % 10;
        j = j / 10;
        sum = count + 10 * sum;
    }
    return sum;
}