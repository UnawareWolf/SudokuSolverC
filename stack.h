typedef struct board {
    int** values;
} board;

typedef struct bStack {
    board* b;
    struct bStack* next;
} bStack;

bStack* newNode(board* b);
void push(bStack** root, board* data);
board* pop(bStack** root);
int isEmpty(bStack* root);