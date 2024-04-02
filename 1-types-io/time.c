/**
 * File: time.c
 *
 * Author:左皓升
 * ID:211250074
 * Date:2021.10.16
 */
#include<stdio.h>
int main() {
  /**
   * input example: November 17 1968 Sunday 6 6 6
   * output example: Sun Nov 17 06:06:06 1968
   */
  char month[] = "to_be_known" ;
  char weekday[] ="to_be_konwn_too";
  int day,year,hour,minute,second;
  scanf("%s %d %d %s %d %d %d", month, &day, &year, weekday, &hour, &minute, &second);
  
  printf("%.3s %.3s %.2d %.2d:%.2d:%.2d %.4d",weekday,month,day,hour,minute,second,year);

  return 0;
}