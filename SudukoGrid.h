#define TRUE 1
#define FALSE 0
#define MIN_VALUE '1'
#define MAX_VALUE '9'
#define EMPTY_VALUE '.'
#define NUM_VALUES (MAX_VALUE - MIN_VALUE + 1)
#define GRID_SIZE (NUM_VALUES * NUM_VALUES)
#define BOX_SIZE (int) sqrt(NUM_VALUES)
#define MIN_CELL 0
#define MAX_CELL (GRID_SIZE - 1)

typedef int cell;
typedef char value;
typedef struct sudukoGrid *SudukoGrid;

SudukoGrid newSudukoGrid (void);

void readGame (SudukoGrid game);

void showGame (SudukoGrid game);

void setCell (SudukoGrid game, cell location, value digit);

value getCell (SudukoGrid game, cell location);

void clearCell (SudukoGrid game, cell location);

int  isFull (SudukoGrid game);

cell getFreeCell (SudukoGrid game);

int  isLegal (SudukoGrid game, cell location, value candidateDigit);