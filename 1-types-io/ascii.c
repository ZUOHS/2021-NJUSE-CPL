/**
 * File: ascii.c
 *
 * Author: 左皓升
 * ID: 211250074
 * Date: 2021.10.14
 */
#include<stdio.h>
#include<ctype.h>

int main() {

    int number;

    scanf("%d", &number);

    printf("%d\n", number);
    printf("%c\n", tolower(number));
    printf("%c\n", toupper(number));

    return 0;
}