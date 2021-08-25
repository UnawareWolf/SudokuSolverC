#include <stdlib.h>
#include "stack.h"

bStack* newNode(board* b)
{
    bStack* node = (bStack*) malloc(sizeof(bStack));
    node->b = b;
    node->next = NULL;
    return node;
}

void push(bStack** root, board* data)
{
    bStack* node = newNode(data);
    node->next = *root;
    *root = node;
}

board* pop(bStack** root)
{
    bStack* temp = *root;
    *root = (*root)->next;
    board* popped = temp->b;
    free(temp);
    return popped;
}