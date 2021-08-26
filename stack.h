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
void push(bStack** root, board* data);
board* pop(bStack** root);
int isEmpty(bStack* root);

void add(slotList** root, slot* s);
void clear(slotList** root);
int hasNext(slotList* node);