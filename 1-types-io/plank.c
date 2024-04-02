/**
 * File: inverse.c
 *
 * Author:左皓升
 * ID:211250074
 * Date:2021.10.16
 */

#include <stdio.h>
#include <math.h>
int main(){
    double frequency = 0;
    scanf("%lf", &frequency);

    printf("%.2e",6.626e-34 * frequency);

    return 0;
}