#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *last;
    int val;
    struct node *next;
} Node;

void Pour(Node *a, Node *b, int *lena, int *lenb);

int main () {
    int n = 0;
    int m = 0;
    scanf("%d%d", &n, &m);
    Node *ptr = malloc(n * sizeof(*ptr));
    int *len = malloc(n * sizeof(*len));
    for (int i = 0; i < n; i++) {
        Node *node = malloc(sizeof(*node));
        (ptr + i)->val = 0;
        (ptr + i)->last = ptr + i;
        (ptr + i)->next = node;
        node->last = ptr + i;
        node->val = i + 1;
        node->next = node;
        *(len + i) = 1;
        //结束的标志是next指向自己
    }
    for (int i = 0; i < m; i++) {
        int a = 0;
        int b = 0;
        scanf("%d%d", &a, &b);
        Pour(ptr + a - 1, ptr + b - 1, len + a - 1, len + b - 1);
        *(len + b - 1) += *(len + a - 1);
        *(len + a - 1) = 0;
    }
    for (int i = 0; i < n; i++) {
        Node *temp = ptr + i;
        if (temp->next == temp) {
            printf("0\n");
        } else {
            temp = temp->next;
            while(temp->next != temp) {
                printf("%d ", temp->val);
                temp = temp->next;
            }
            printf("%d\n", temp->val);
        }
    }
}

void Pour(Node *a, Node *b, int *lena, int *lenb) {
    Node *positiona = a;
    Node *positionb = b;
    if (*lena == 0) {
        return;
    }
    for (int i = 0; i < *lena; i++) {
        positiona = positiona->next;
    }
    for (int i = 0; i < *lenb; i++) {
        positionb = positionb->next;
    }
    for (int i = 0; i < *lena; i++) {
        Node *node = malloc(sizeof(*node));
        node->val = positiona->val;
        positiona = positiona->last;
        free(positiona->next);
        positiona->next = positiona;
        //deal with a
        node->next = node;
        node->last = positionb;
        positionb->next = node;
        positionb = node;
    }
}