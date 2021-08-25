#include <stdio.h>
#include <stdlib.h>
#include "solver.h"

typedef struct board {
    int** values;
} board;

// typedef struct stack {
//     int number;
//     struct stack* next;
// } stack;

typedef struct bStack {
    int** values;
    struct bStack* next;
} bStack;

// void push(stack** root, int **val)
// {
//     stack* node = (stack*) malloc(sizeof(stack));
//     int i, j;
//     // for (i = 0; i < BSIZE; i++) {
//     //     for (j = 0; j < BSIZE; j++) {
//     //         node->number[i][j] = (*val)[i][j];
//     //         // scanf("%i,\n", &board[i][j]);
//     //     }
//     // }
//     // node->number = val;
//     // node->next = *root;
//     // *root = node;
// }

// void pop(stack** root, int* val)
// {
//     // stack* temp = *root;
//     // *root = (*root)->next;
//     // int* popped = temp->number;
//     // free(temp);
//     // val = popped;
// }

bStack* newNode(int** data)
{
    bStack* node = (bStack*) malloc(sizeof(bStack));
    node->values = data;
    node->next = NULL;
    return node;
}

void push(bStack** root, int** data)
{
    bStack* node = newNode(data);
    node->next = *root;
    *root = node;
}

int** pop(bStack** root)
{
    bStack* temp = *root;
    *root = (*root)->next;
    int** popped = temp->values;
    free(temp);
    return popped;
}

int main()
{
    puts("Hello, Sudoku!");
    board b2;
    int board[BSIZE][BSIZE];
    int i, j;

    b2.values = malloc(9*sizeof(int*));
    for (i=0;i<9;i++) b2.values[i] = malloc(9*sizeof(int));

    
    for (i = 0; i < BSIZE; i++) {
        for (j = 0; j < BSIZE; j++) {
            scanf("%i,\n", &board[i][j]);
            b2.values[i][j] = board[i][j];
        }
    }

    printBoard(b2.values);

    // free(b2.values);

    struct bStack* root = NULL;

    push(&root, b2.values);

    printBoard(pop(&root));

    // printBoard(b2.values);

    

    // stack* myStack = NULL;

    // push(&myStack, &board);
    // int b2[BSIZE][BSIZE];
    // pop(&myStack, &b2);
    // printBoard(b2);
    // push(&myStack, 10);
    // push(&myStack, 20);
    // int pop1, pop2;
    // pop(&myStack, &pop1);
    // pop(&myStack, &pop2);
    // printf("%i\n", (&pop1)[1]);
    // printf("%i\n", pop2);

    // stack boards = {.board = *board, .head = NULL};
    // printf("%i", *(createArray() + 1));

    return 0;
}

// void printBoard(int board[BSIZE][BSIZE])
// {
//     int i, j;
//     for (i = 0; i < BSIZE; i++) {
//         for (j = 0; j < BSIZE; j++) {
//             printf("%i", board[i][j]);
//             if (j != BSIZE - 1)
//                 printf(",");
//             else printf("\n");
//         }
//     }
//     puts("");
// }

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

// int createArray()
// {
//     int newArray[2];
//     newArray[0] = 3;
//     newArray[1] = 5;
//     return *newArray;
// }
