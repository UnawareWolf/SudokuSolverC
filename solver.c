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
    slotList* slotHead = NULL;
    push(&root, b1);
    int count = 0;
    while (!isEmpty(root)) {
        count++;
        current = pop(&root);
        printBoard(current);

        slotHead = getEmptySlots(current);

        if (slotHead == NULL) {
            puts("Solved!");
            break;
        }

        slotList* currentSlot = slotHead;
        while (currentSlot->next != NULL) {
            // printf("row %i col %i\n", currentSlot->s->row, currentSlot->s->col);
            currentSlot = currentSlot->next;
        }
    }

    // slot s1 = {2, 1};
    // slot s2 = {3, 4};
    // slot s3 = {5, 6};
    
    // slotList* head = NULL;

    // add(&head, &s1);
    // add(&head, &s2);
    // printf("%i\n", head->s->col);


    return 0;
}

slotList* getEmptySlots(board* b)
{
    slotList* head = NULL;
    int i, j;
    for (i = 0; i < BSIZE; i++) {
        for (j = 0; j < BSIZE; j++) {
            if (b->values[i][j] == 0) {
                slot* s = (slot*) malloc(sizeof(slot));
                s->row = i;
                s->col = j;
                add(&head, s);
            }
        }
    }
    return head;
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
