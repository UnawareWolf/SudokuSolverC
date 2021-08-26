#include <stdlib.h>
#include <stdio.h>
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

int isEmpty(bStack* root)
{
    return !root;
}

int hasNext(slotList* node)
{
    return !(&(node->next));
}

void add(slotList** root, slot* s)
{
    slotList* node = (slotList*) malloc(sizeof(slotList));
    node->s = s;
    node->next = NULL;
    // // slotList* current = root;
    // // printf("%i\n", hasNext(current));
    if (*root == NULL) {
        puts("root was null");
        // *root = (slotList*) malloc(sizeof(slotList));
        // current = node;
        *root = node;
        // (*root)->next = NULL;
        // (*root)->s = s;
    }
    else {
        slotList* current = *root;
        puts("not null");
        while (current->next != NULL) {
            printf("hi %i\n", current->s->col);
            current = current->next;
        }
        // slotList* node = (slotList*) malloc(sizeof(slotList));
        // node->s = s;
        // node->next = NULL;
        current->next = node;
    }
    
    
}

void clear(slotList** root)
{

}