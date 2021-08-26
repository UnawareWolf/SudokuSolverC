const int BSIZE = 9;
void printBoard(board* b);
board* createBoard();
void fillBoard(board* b, int fill);
void scanBoard(board* b);
void copyBoard(board* b1, board* b2);
board* updateBoard(int guess, slot* s, board* b);
slotList* getEmptySlots(board* b);
board* doPerfectMove(slotList* slotHead, board* b);
int isValidInSlot(int guess, slot* s, board* b);
int isValidInRow(int guess, slot* s, board* b);
int isValidInCol(int guess, slot* s, board* b);
int isValidInSquare(int guess, slot* s, board* b);

int onlyValidGuessInSlot(int guess, slot* s, board* b);
int otherGuessesInvalidInSlot(int guess, slot* s, board* b);
int onlyValidSlotInRow(int guess, slot* s, board* b);
int onlyValidSlotInCol(int guess, slot* s, board* b);
int onlyValidSlotInSquare(int guess, slot* s, board* b);

void freeSlots(slotList* slotHead);
void freeBoard(board* b);