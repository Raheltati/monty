#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int data;
    struct Stack* next;
} Stack;

void push(Stack** top, int data) {
    Stack* new_node = (Stack*)malloc(sizeof(Stack));
    new_node->data = data;
    new_node->next = NULL;

    if (*top == NULL) {
        *top = new_node;
    } else {
        Stack* temp = *top;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print_stack(Stack* top) {
    Stack* temp = top;
    if (top == NULL) {
        return;
    }
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    Stack* top = NULL;

    push(&top, 3);
    push(&top, 2);
    push(&top, 1);

    printf("Stack elements:\n");
    print_stack(top);

    return 0;
}

