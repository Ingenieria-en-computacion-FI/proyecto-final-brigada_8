#include <stdlib.h>
#include "stack.h"

/* Nodo de la pila */
typedef struct Node {

    int value;
    struct Node* next;

} Node;

/* Definición real de Stack */
struct Stack {

    Node* top;

};

/* Crear pila vacía */
Stack* stack_create() {

    Stack* stack = malloc(sizeof(Stack));

    if (stack == NULL)
        return NULL;

    stack->top = NULL;

    return stack;
}

/* Insertar elemento */
void stack_push(
    Stack* stack,
    int value
) {

    if (stack == NULL)
        return;

    Node* new_node = malloc(sizeof(Node));

    if (new_node == NULL)
        return;

    new_node->value = value;
    new_node->next = stack->top;

    stack->top = new_node;
}

/* Eliminar elemento superior */
int stack_pop(
    Stack* stack
) {

    if (stack == NULL || stack->top == NULL)
        return -1;

    Node* temp = stack->top;

    int value = temp->value;

    stack->top = temp->next;

    free(temp);

    return value;
}

/* Consultar elemento superior */
int stack_peek(
    Stack* stack
) {

    if (stack == NULL || stack->top == NULL)
        return -1;

    return stack->top->value;
}

/* Verificar si está vacía */
int stack_is_empty(
    Stack* stack
) {

    if (stack == NULL)
        return 1;

    return stack->top == NULL;
}

/* Liberar memoria */
void stack_destroy(
    Stack* stack
) {

    if (stack == NULL)
        return;

    while (!stack_is_empty(stack))
        stack_pop(stack);

    free(stack);
}
