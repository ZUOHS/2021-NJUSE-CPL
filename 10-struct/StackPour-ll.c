#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    struct node *last;
    int val;
    struct node *next;
} Node;

void Pour(Node *a, Node *b);

int main () {
    int n = 0;
    int m = 0;
    scanf("%d%d", &n, &m);
    Node *ptr = malloc(n * sizeof(*ptr));
    int *len = malloc(n * sizeof(*len));
    if (ptr == NULL) {
        printf("Fail");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        (ptr + i)->val = i + 1;
        (ptr + i)->next = ptr + i;
        (ptr + i)->last = ptr + i;
        *(len + i) = 1;
    }
    for (int i = 0; i < m; i++) {
        int a = 0;
        int b = 0;
        scanf("%d%d", &a, &b);
        Pour(ptr + a - 1, ptr + b - 1);
    }
    for (int i = 0; i < n; i++) {
        if ((ptr + i)->val == 0) {
            printf("0\n");
        } else {
            Node *temp = ptr + i;
            do {
                printf("%d ", temp->val);
                temp = temp->next;
            } while (temp->next != temp && temp->val != 0);
            printf("\n");
        }
    }
    
}

void Pour(Node *a, Node *b) {
    if (a->val == 0) {
        return;
    }
    int count = 0;
    Node *position1 = a;
    Node *position2 = b;
    for (int i = 0; i < 1000; i++) {
        count++;
        if (position1->val == 0) {
            count--;
            position1 = position1->last;
            break;
        }
        position1 = position1->next;
        if (position1 == position1->last) {
            break;
        }
    }
    for (int i = 0; i < 1000; i++) {
        position2 = position2->next;
        if (position2->val == 0) {
            position2 = position2->last;
            break;
        }
        if (position2 == position2->next) {
            break;
        }
    }
    if (position2->val != 0) {
        for (int i = 0; i < count; i++) {
            Node *node = malloc(sizeof(*node));
            node->val = position1->val;
            position1->val = 0;
            node->last = position2;
            position2->next = node;
            node->next = node;
            position2 = position2->next;
            position1 = position1->last;
            position1->next = position1;
        }
    } else if (position2->val == 0) {
        position2->val = position1->val;
        position1 = position1->last;
        for (int i = 1; i < count; i++) {
            Node *node = malloc(sizeof(*node));
            node->val = position1->val;
            position1->val = 0;
            node->last = position2;
            position2->next = node;
            node->next = node;
            position2 = position2->next;
            position1 = position1->last;
            position1->next = position1;
        }
    }
}