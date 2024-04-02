/**
 * File: equation.c
 *
 * Author:左皓升
 * ID:211250074
 * Date:2021.10.15
 */

#include <stdio.h>
#include <math.h>
int main() {
  // Well, `a`, `b`, `c` are actually meaningful identifiers here.
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  double i = (-b-sqrt(b*1.0*b - 4.0*a*c)) / (2.0 * a) ;
  double j = (-b+sqrt(b*1.0*b - 4.0*a*c)) / (2.0 * a) ;
  printf("%.3f %.3f\n",i,j);
  return 0;
}