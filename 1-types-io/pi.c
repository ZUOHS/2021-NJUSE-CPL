/**
 * File: pi.c
 *
 * Author:左皓升
 * ID:211250074
 * Date:2021.10.16
 */
#include<stdio.h>
#include<math.h>

int main() {
  double i = 16*atan(1/5.0)-4*atan(1/239.0);
  double j = log(640320*1.0*640320*640320+744)/(sqrt(163));
  

  printf("%.15f\n%.15f\n",i,j);
  return 0;
}