#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *last;
    int val;
    struct node *next;
} Node;

typedef struct ll {
    Node *head;
    Node *position;
    Node *tail;
} Linklist;


void Append (Linklist *list, int val);
void Forward (Linklist *list, int n);
void Backward (Linklist *list, int n);
void Insert (Linklist *list, int n);
void Remove (Linklist *list);

int main () {
    int *save = malloc(200000 * sizeof(*save));
    int count2 = 0;
    int a = 0;
    int b = 0;
    Linklist List;
    Linklist *list = &List;
    list->position = NULL;
    list->head = NULL;
    list->tail = NULL;
    scanf("%d%d", &a, &b);
    int count = a;
    for (int i = 1; i <= a; i++) {
        Append(list, i);
    }
    for (int i = 0; i < b; i++) {
        char *order = malloc(10 * sizeof(*order));
        int n = 0;
        scanf("%s", order);
        int step = 0;
        if (*order == 'F') {
            scanf("%d", &n);
            step = n % count;
            if (step > count / 2) {
                step = count - step;
                Backward(list, step);
            } else {
                Forward(list, step);
            }
        } else if (*order == 'B') {
            scanf("%d", &n);
            step = n % count;
            if (step > count / 2) {
                step = count - step;
                Forward(list, step);
            } else {
                Backward(list, step);
            }
        } else if (*order == 'I') {
            scanf("%d", &n);
            Insert(list, n);
            count++;
        } else if (*order == 'R') {
            Remove(list);
            count--;
        } else if (*order == 'P') {
            *(save + count2) = list->position->val;
            count2++;
        }
    }
    for (int i = 0; i < count2; i++) {
        printf("%d\n", *(save + i));
    }
}

void Append (Linklist *list, int val) {
    Node *node = malloc(sizeof *node);
    if (node == NULL) {
        printf("Fail");
        return;
    }
    node->val = val;
    if (val == 1) {
        list->head = node;
        list->position = node;
        list->tail = node;
        node->next = node;
        node->last = node;
    } else  {
        list->tail->next = node;
        node->last = list->tail;
        node->next = list->head;
        list->head->last = node;
        list->tail = node;
    }
}

void Forward (Linklist *list, int n) {
    for (int i = 0; i < n; i++) {
        list->position = list->position->next;
    }
}

void Backward (Linklist *list, int n) {
    for (int i = 0; i < n; i++) {
        list->position = list->position->last;
    }
}

void Insert (Linklist *list, int n) {
    Node *node = malloc(sizeof *node);
    if (node == NULL) {
        printf("Fail2");
        return;
    }
    node->val = n;
    node->next = list->position->next;
    list->position->next->last = node;
    list->position->next = node;
    node->last = list->position;
}

void Remove (Linklist *list) {
    list->position->last->next = list->position->next;
    list->position->next->last = list->position->last;
    list->position = list->position->next;
}