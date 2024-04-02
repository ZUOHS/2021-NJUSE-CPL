/**
 * File: weekday.c
 *
 * Author:左皓升
 * ID:211250074
 * Date:2021.10.16
 */
#include<stdio.h>
#include<math.h>
int main() {
    int year,month,day;
    scanf("%d %d %d", &year, &month, &day);
    int i,j;
    if((year % 4 == 0)&(year % 100 != 0)){
        j = 1;
    }else if(year % 400 == 0){
        j = 1;
    }else{
        j = 0;
    }
    if(month == 1){
        i = day;
    }else if(month == 2){
        i = 31 + day;
    }else{
        i = (13*(month+1)/5)-7+(month-1)*28+day+j;
    }
    int W = year-1+(year-1)/4-(year-1)/100+(year-1)/400+i;
    int output = W % 7;

    printf("%d",output);

    return 0;
}