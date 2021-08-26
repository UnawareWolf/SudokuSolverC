typedef struct board {
    int** values;
} board;

typedef struct bStack {
    board* b;
    struct bStack* next;
} bStack;

typedef struct {
    int row;
    int col;
} slot;

typedef struct slotList {
    slot* s;
    struct slotList* next;
} slotList;

bStack* newNode(board* b);
void pushBoard(bStack** root, board* data);
board* popBoard(bStack** root);
int isEmpty(bStack* root);

void addSlot(slotList** root, slot* s);