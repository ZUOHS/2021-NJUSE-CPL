#include <stdio.h>
int main(){

  int n = 0;;
  scanf("%d", &n);
  int a[n];
  for (int i = 1; i <= n; i++) {
    a[i] = 0;
  }
  int b[2 * n];
  for (int i = 1; i <= 2 * n; i++) {
    b[i] = 0;
  }
  for (int i = 1; i <= 2 * n - 1; i++){
    scanf("%d", &b[i]);
    a[b[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] != 2) {
      printf("%d", i);
      break;
  }

  return 0;
}
