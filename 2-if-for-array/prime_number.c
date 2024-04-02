#include <stdio.h>
#include <math.h>


int main() {
  int max = 0;
  scanf("%d", &max);
  int count = 1;
  
for(int i = 2; i <= max; i++) {
  int is_prime = 1;
    for (int j = 2; j <= ceil(sqrt(i)); j++) {
      if (i % j == 0) {
        is_prime = 0;
        break;
      }
    }
    if (is_prime == 1) {
      count++;
    }
  }
printf("%d", count);
  return 0;
}