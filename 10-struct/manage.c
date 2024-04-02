#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    struct node *father;
    char *value;
    struct node *son;
    struct node *daughter;
} Node;

typedef struct list {
    struct node *ptr;
    char *ch;
    struct list *next;
} List;

void Store (char *left, char *right, List *begin);
int Count (char *a, List *begin);
int Number (Node *temp);
void Delete (char *a, List *begin);

int main () {
    int m = 0;
    int n = 0;
    scanf("%d%d", &m, &n);
    char waste[5];
    List *begin = malloc(sizeof(*begin));
    Node *start = malloc(sizeof(*start));
    char *first = malloc(11 * sizeof(char));

    scanf("%s%s", first, waste);
    start->value = first;
    begin->ch = first;

    begin->next = begin;
    begin->ptr = start;
    start->father = start;
    start->son = start;
    start->daughter = start;

    for (int i = 1; i < m; i++) {
        char *left = malloc(11 * sizeof(*left));
        char *right = malloc(11 * sizeof(*right));
        scanf("%s%s", left, right);
        Store (left, right, begin);
    }

    for (int i = 0; i < n; i++) {
        char *order = malloc(11 *sizeof(*order));
        char *a = malloc(11 * sizeof(*a));
        scanf("%s%s", order, a);
        if (*order == 'q') {
            printf("%d\n", Count(a, begin));
        } else {
            Delete(a, begin);
        }
    }
}

void Store (char *left, char *right, List *begin) {
    List *list = malloc(sizeof(*list));
    Node *node = malloc(sizeof(*node));
    list->next = list;
    list->ptr = node;
    node->daughter = node;
    node->son = node;
    node->father = node;
    list->ch = left;
    node->value = left;

    List *position = begin;
    while(position->next != position) {
        position = position->next;
    }
    position->next = list;
    position = begin;
    while (position->next != position) {
        if (strcmp(position->ch, right) == 0) {
            break;
        }
        position = position->next;
    }
    node->father = position->ptr;
    Node *temp = position->ptr;
    if (temp->son == temp) {
        temp->son = node;
    } else if (temp->son != temp) {
        temp->daughter = node;
    }
}

int Count (char *a, List *begin) {
    List *position = begin;
    while (position->next != position) {
        if (strcmp(position->ch, a) == 0) {
            break;
        }
        position = position->next;
    }
    Node *temp = position->ptr;
    return Number(temp);
}

int Number (Node *temp) {
    if (temp->son == temp && temp->daughter == temp) {
        return 1;
    }
    if (temp->son == temp && temp->daughter != temp) {
        return (1 + Number(temp->daughter));
    }
    if (temp->daughter == temp && temp->son != temp) {
        return (1 + Number(temp->son));
    }
    if (temp->daughter != temp && temp->son != temp) {
        return (1 + Number(temp->son) + Number(temp->daughter));
    }
}

void Delete (char *a, List *begin) {
    List * position = begin;
    while (position->next != position) {
        if (strcmp(a, position->ch) == 0) {
            break;
        }
        position = position->next;
    }
    Node *temp = position->ptr;
    if (temp->father->son == temp) {
        temp->father->son = temp->father;
    } else {
        temp->father->daughter = temp->father;
    }
    free(temp);
}