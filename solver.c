#include <stdio.h>
#include <stdlib.h>
#include "solver.h"

typedef struct board {
    int** values;
} board;

typedef struct bStack {
    board* b;
    struct bStack* next;
} bStack;

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

int main()
{
    puts("Hello, Sudoku!");
    board b2;
    int myboard[BSIZE][BSIZE];
    int i, j;

    b2.values = malloc(9*sizeof(int*));
    for (i=0;i<9;i++) b2.values[i] = malloc(9*sizeof(int));

    
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
