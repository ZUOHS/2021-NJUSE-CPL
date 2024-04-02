#include <stdio.h>
#include <stdlib.h>

void Forward (int *array, int *num);
void Backward (int *array, int *num);
void Insert (int *array, int *num);
void Remove (int *array);

int count = 0;
int position = 1;

int main () {
    int *save = malloc(20000000 * sizeof(*save));
    int count2 = 0;
    int a = 0;
    int b = 0;
    int *array = malloc(20000000 * sizeof(*array));
    scanf("%d%d", &a, &b);
    count = a;
    for (int i = 1; i <= a; i++) {
        *(array + i) = i;
    }

    for (int i = 0; i < b; i++) {
        char *order = malloc(10 * sizeof(*order));
        int n = 0;
        int *num = &n;
        scanf("%s", order);
        if (*order == 'F') {
            scanf("%d", num);
            Forward(array, num);
        } else if (*order == 'B') {
            scanf("%d", num);
            Backward(array, num);
        } else if (*order == 'I') {
            scanf("%d", num);
            Insert(array, num);
            count++;
        } else if (*order == 'R') {
            Remove(array);
            count--;
        } else if (*order == 'P') {
            *(save + count2) = *(array + position);
            count2++;
        }
    }
    for (int i = 0; i < count2; i++) {
        printf("%d\n", *(save + i));
    }
}

void Forward (int *array, int *num) {
    int step = *num % count;
    if (*num % count == 0) {
        return;
    }
    for (int i = 0; i < *num % count; i++) {
        if (position == count) {
            position = 1;
        } else {
            position++;
        }
    }
}

void Backward (int *array, int *num) {
    int step = *num % count;
    if (*num % count == 0) {
        return;
    }
    for (int i = 0; i < count - step; i++) {
        if (position == count) {
            position = 1;
        } else {
            position++;
        }
    }
}

void Insert (int *array, int *num) {
    for (int i = count + 1; i > position + 1; i--) {
        array[i] = array[i - 1];
    }
    array[position + 1] = *num;
}

void Remove (int *array) {
    for (int i = position; i < count; i++) {
        array[i] = array[i + 1];
    }
    array[count] = 0;
}  