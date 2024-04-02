#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node {
    char *value;
    struct node *next;
} Node;

void Store (Node *temp, char *a);
int Check (Node *temp, char *a);
int Trans(char *a);

int main () {
    int n = 0;
    int m = 0;
    Node *ptr = malloc(1000000 * sizeof(*ptr));
    for (int i = 0; i < 1000000; i++) {
        Node *temp = ptr + i;
        temp->value = NULL;
        temp->next = temp;
    }
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        char *a = malloc(1003 * sizeof(*a));
        scanf("%s", a);
        int len = strlen(a);
        int key = 0;
        key = Trans(a);
        Store(ptr + key, a);
        free(a);
    }
    int *judge = malloc(m * sizeof(*judge));
    for (int i = 0; i < m; i++) {
        char *a = malloc(1003 * sizeof(*a));
        scanf("%s", a);
        int key = 0;
        key = Trans(a);
        *(judge + i) = Check(ptr + key, a);
        free(a);
    }
    for (int i = 0; i < m; i++) {
        if (*(judge + i)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}

void Store (Node *temp, char *a) {
    Node *position = temp;
    while (position->next != position) {
        position = position->next;
    }
    int len = (int)strlen(a) + 1;
    Node *node = malloc(sizeof(*node));
    node->value = malloc(len * sizeof(char));
    strcpy(node->value, a);
    position->next = node;
    node->next = node;
}

int Check (Node *temp, char *a) {
    Node *position = temp;
    while (position->next != position) {
        position = position->next;
        if (*(position->value) == *a) {
            if (strcmp(position->value, a) == 0) {
                return 1;
            }
        }
    }
    return  0;
}

int Trans(char *a) {
    int key = 0;
    int len = strlen(a);
    if (len > 5) {
        len = 5;
    }
    for (int i = 0; i <len; i++) {
        int temp = 0;
        if (*(a + i) >= 97 && *(a + i) <= 122) {
            temp = *(a + i) - 97;
        } else if (*(a + i) >= 65 && *(a + i) <= 90) {
            temp = *(a + i) - 39;
        }
        key = 10 * key + temp;
    }
    return key;
}