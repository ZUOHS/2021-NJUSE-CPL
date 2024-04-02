/**
 * File: inverse.c
 *
 * Author:左皓升
 * ID:211250074
 * Date:2021.10.16
 */
#include<stdio.h>
#include<math.h>

int main() {
  int number;
  int output;
  scanf("%d", &number);
  int i = number%10;
  int j = (number/10)%10;
  int k = number/100;
  printf("%d%d%d",i,j,k);
  return 0;
}