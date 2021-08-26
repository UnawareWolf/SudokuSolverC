#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "solver.h"

int main()
{
    board* b1 = createBoard();
    board* temp = createBoard();
    board* current = createBoard();
    scanBoard(b1);
    bStack* root = NULL;
    push(&root, b1);
    int count = 0;
    while (!isEmpty(root)) {
        count++;
        current = pop(&root);
        printBoard(current);
    }

    slot s1 = {2, 1};
    slot s2 = {3, 4};
    slot s3 = {5, 6};
    
    slotList* head = NULL;
    slotList* second = NULL;

    // head = (slotList*) malloc(sizeof(slotList));
    // second = (slotList*) malloc(sizeof(slotList));

    // head->s = &s1;
    // head->next = second;

    // second->s = &s2;
    // second->next = NULL;

    // add(head, &s3);


    add(&head, &s1);
    add(&head, &s2);
    printf("%i\n", head->next->s->col);
    // add(list, &s3);


    return 0;
}

board* createBoard()
{
    board* b = (board*) malloc(sizeof(board));
    int i;
    b->values = malloc(BSIZE*sizeof(int*));
    for (i = 0; i < BSIZE; i++)
        b->values[i] = malloc(BSIZE * sizeof(int));
    return b;
}

void copyBoard(board* b1, board* b2)
{
    int i, j;
    for (i = 0; i < BSIZE; i++)
        for (j = 0; j < BSIZE; j++)
            b2->values[i][j] = b1->values[i][j];
}

void fillBoard(board* b, int fill)
{
    int i, j;
    for (i = 0; i < BSIZE; i++)
        for (j = 0; j < BSIZE; j++)
            b->values[i][j] = fill;
}

void scanBoard(board* b) {
    int i, j;
    for (i = 0; i < BSIZE; i++)
        for (j = 0; j < BSIZE; j++)
            scanf("%i,", &(b->values[i][j]));
}

void printBoard(board* b)
{
    int i, j;
    for (i = 0; i < BSIZE; i++) {
        for (j = 0; j < BSIZE; j++) {
            printf("%i", b->values[i][j]);
            if (j != BSIZE - 1)
                printf(",");
            else printf("\n");
        }
    }
    puts("");
}
