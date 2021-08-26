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
        current = pop(&root);
        printBoard(current);

        slotHead = getEmptySlots(current);
        
        if (slotHead == NULL) {
            puts("Solved!");
            break;
        }

        temp = doPerfectMove(slotHead, current);
        if (temp != NULL) {
            push(&root, temp);
        }

        if (isEmpty(root)) {
            slotList* currentSlot = slotHead;
            int guess;
            while (currentSlot != NULL) {
                for (guess = 1; guess <= 9; guess++) {
                    if (isValidInSlot(guess, currentSlot->s, current)) {
                        push(&root, updateBoard(guess, currentSlot->s, current));
                    }
                }
                currentSlot = currentSlot->next;
            }
        }
        
        freeSlots(slotHead);
        freeBoard(current);
        count++;
    }
    printf("%i moves\n", count);

    return 0;
}

board* doPerfectMove(slotList* slotHead, board* b)
{
    int guess;
    slotList* currentSlot = slotHead;
    while (currentSlot != NULL) {
        for (guess = 1; guess <= 9; guess++) {
            if (onlyValidGuessInSlot(guess, currentSlot->s, b)) {
                return updateBoard(guess, currentSlot->s, b);
            }
        }
        currentSlot = currentSlot->next;
    }
    return NULL;
}

board* updateBoard(int guess, slot* s, board* b)
{
    board* newBoard = createBoard();
    copyBoard(b, newBoard);
    newBoard->values[s->row][s->col] = guess;
    return newBoard;
}

int onlyValidGuessInSlot(int guess, slot* s, board* b)
{
    if (!isValidInSlot(guess, s, b))
        return 0;
    return otherGuessesInvalidInSlot(guess, s, b) ||
        onlyValidSlotInRow(guess, s, b) ||
        onlyValidSlotInCol(guess, s, b) ||
        onlyValidSlotInSquare(guess, s, b);
}

int otherGuessesInvalidInSlot(int guess, slot* s, board* b)
{
    int newGuess;
    for (newGuess = 1; newGuess <= 9; newGuess++) {
        if (newGuess == guess) {
            continue;
        }
        if (isValidInSlot(newGuess, s, b)) {
            return 0;
        }
    }
    return 1;
}

int onlyValidSlotInRow(int guess, slot* s, board* b)
{
    int i;
    for (i = 0; i < BSIZE; i++) {
        if (i == s->row) {
            continue;
        }
        slot newSlot = {i, s->col};
        if (b->values[i][s->col] == 0 && isValidInSlot(guess, &newSlot, b)) {
            return 0;
        }
    }
    return 1;
}

int onlyValidSlotInCol(int guess, slot* s, board* b)
{
    int j;
    for (j = 0; j < BSIZE; j++) {
        if (j == s->col) {
            continue;
        }
        slot newSlot = {s->row, j};
        if (b->values[s->row][j] == 0 && isValidInSlot(guess, &newSlot, b)) {
            return 0;
        }
    }
    return 1;
}

int onlyValidSlotInSquare(int guess, slot* s, board* b)
{
    int i, j, rowMod, colMod;

    rowMod = (s->row / 3) * 3;
    colMod = (s->col / 3) * 3;

    for (i = rowMod; i < rowMod + 3; i++) {
        for (j = colMod; j < colMod + 3; j++) {
            if (i == s->row && j == s->col) {
                continue;
            }
            slot newSlot = {i, j};
            if (b->values[i][j] == 0 && isValidInSlot(guess, &newSlot, b)) {
                return 0;
            }
        }
    }
    
    return 1;
}

int isValidInSlot(int guess, slot* s, board* b)
{
    return isValidInRow(guess, s, b) &&
        isValidInCol(guess, s, b) &&
        isValidInSquare(guess, s, b);
}

int isValidInRow(int guess, slot* s, board* b)
{
    int i;
    for (i = 0; i < BSIZE; i++) {
        if (b->values[i][s->col] == guess) {
            return 0;
        }
    }
    return 1;
}

int isValidInCol(int guess, slot* s, board* b)
{
    int j;
    for (j = 0; j < BSIZE; j++) {
        if (b->values[s->row][j] == guess) {
            return 0;
        }
    }
    return 1;
}

int isValidInSquare(int guess, slot* s, board* b)
{
    int i, j, rowMod, colMod;

    rowMod = (s->row / 3) * 3;
    colMod = (s->col / 3) * 3;

    for (i = rowMod; i < rowMod + 3; i++) {
        for (j = colMod; j < colMod + 3; j++) {
            if (b->values[i][j] == guess) {
                return 0;
            }
        }
    }
    
    return 1;
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
    b->values = malloc(BSIZE * sizeof(int*));
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

void freeSlots(slotList* slotHead)
{
    slotList* currentSlot = slotHead;
    slotList* lastSlot;
    while (currentSlot != NULL) {
        free(currentSlot->s);
        lastSlot = currentSlot;
        currentSlot = currentSlot->next;
        free(lastSlot);
    }
}

void freeBoard(board* b)
{
    free(b->values);
    free(b);
}
