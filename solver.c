#include <stdio.h>
#include <stdlib.h>
#include "solver.h"
#include "stack.h"

int main()
{
    puts("Hello, Sudoku!");
    board b2;
    int myboard[BSIZE][BSIZE];
    int i, j;

    b2.values = malloc(BSIZE*sizeof(int*));
    for (i=0;i<BSIZE;i++) b2.values[i] = malloc(BSIZE*sizeof(int));

    
    for (i = 0; i < BSIZE; i++) {
        for (j = 0; j < BSIZE; j++) {
            scanf("%i,\n", &myboard[i][j]);
            b2.values[i][j] = myboard[i][j];
        }
    }

    // free(b2.values);

    struct bStack* root = NULL;

    push(&root, &b2);

    printBoard(pop(&root)->values);

    return 0;
}

void printBoard(int** board)
{
    int i, j;
    for (i = 0; i < BSIZE; i++) {
        for (j = 0; j < BSIZE; j++) {
            printf("%i", board[i][j]);
            if (j != BSIZE - 1)
                printf(",");
            else printf("\n");
        }
    }
    puts("");
}
