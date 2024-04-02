/**
 * File: gray.c
 *
 * Author:左皓升
 * ID:211250074
 * Date:2021.10.16
 */

#include <stdio.h>
#include<math.h>

int main() {
  int number;
  scanf("%d", &number);
  int a,b,c,d,i,j,k,m,n,p,q;
  a = number % 2;
  i = number / 2;
  b = i % 2;
  j = i / 2;
  c = j % 2;
  k = j / 2;
  d = k % 2;
  
  m = d;
  n = d ^ c;
  p = c ^ b;
  q = b ^ a;

  printf("%d%d%d%d",m,n,p,q);

  return 0;
}