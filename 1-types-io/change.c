/**
 * File: change.c
 *
 * Author:左皓升
 * ID:211250074
 * Date:2021.10.15
 */
#include<stdio.h>
#include<math.h>

int main() {
  int money;
  int twd;
  int td;
  int fd;
  int od;
  
  scanf("%d", &money);
  printf("%d\n",money / 20);
  int i = money % 20;
  printf("%d\n",i / 10);
  int j = i % 10;
  printf("%d\n",j / 5);
  printf("%d\n",j % 5);


  return 0;
}
