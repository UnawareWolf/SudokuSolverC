#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "solver.h"


int main()
{
    board* b1 = createBoard();
    board* b2 = createBoard();
    fillBoard(b1, 4);
    board* b3 = createBoard();
    copyBoard(b1, b3);
    b3->values[0][0] = 6;
    scanBoard(b2);
    bStack* root = NULL;
    push(&root, b1);
    push(&root, b2);
    push(&root, b3);
    while (!isEmpty(root)) {
        printBoard(pop(&root));
    }

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
