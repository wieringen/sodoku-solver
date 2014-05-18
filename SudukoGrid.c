#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "SudukoGrid.h"

static int getRow (cell location);
static int getCol (cell location);
static int getBox (cell location);
static int validateCol (SudukoGrid game, cell location, value candidateDigit);
static int validateRow (SudukoGrid game, cell location, value candidateDigit);
static int validateBox (SudukoGrid game, cell location, value candidateDigit);

struct sudukoGrid {
    value contents [GRID_SIZE];
    int numberOccupied;
};

SudukoGrid newSudukoGrid (void) {
    SudukoGrid new;
    new = malloc (sizeof (struct sudukoGrid));

    assert (new != NULL);

    new->numberOccupied = 0;

    cell current = 0;

    while (current <= MAX_CELL) {
        new->contents[current] = EMPTY_VALUE;
        current++;
    }

    return new;
}

void readGame (SudukoGrid game) {
    cell currentCell = 0;
    int inChar = getchar();

    while ((inChar != EOF) && (currentCell <= MAX_CELL)) {
        if((inChar >= MIN_VALUE) &&  (inChar <= MAX_VALUE)) {
            setCell (game, currentCell, inChar);
            currentCell++;
        } else if (inChar == EMPTY_VALUE) {
            clearCell(game, currentCell);
            currentCell++;
        }
        inChar = getchar();
    }
}

void showGame (SudukoGrid game) {
    int i, j;

    for (i = 0; i < NUM_VALUES; i++) {
        if(i % BOX_SIZE == 0) {
            printf("|-------|-------|-------|\n");
        }

        for (j = 0; j < NUM_VALUES; j++) {
            if(j % BOX_SIZE == 0) {
                printf("| ");
            }

            printf("%-c ", getCell(game, (i * NUM_VALUES) + j));
        }
        printf("|\n");
    }

    printf("|-------|-------|-------|\n");
}

value getCell (SudukoGrid game, cell location) {
    return game->contents[location];
}

void setCell (SudukoGrid game, cell location, value digit) {

    if (game->contents[location] == EMPTY_VALUE) {
        game->numberOccupied++;
    }

    game->contents[location] = digit;
}

void clearCell (SudukoGrid game, cell location) {

    if (game->contents[location] != EMPTY_VALUE) {
        game->numberOccupied--;
    }

    game->contents[location] = EMPTY_VALUE;
}

cell getFreeCell (SudukoGrid game) {
    int i;
    cell emptyCell = -1;

    for(i = 0; i < GRID_SIZE; i++)
    {
        if(getCell(game, i) == EMPTY_VALUE)
        {
            emptyCell = i;
            break;
        }
    }

    return emptyCell;
}

int isFull (SudukoGrid game) {
    return (game->numberOccupied == GRID_SIZE);
}

int isLegal (SudukoGrid game, cell location, value candidateDigit) {
    int legal = TRUE;

    if(legal) {
        legal = validateRow(game, location, candidateDigit);

        if(legal) {
            legal = validateCol(game, location, candidateDigit);

            if(legal) {
                legal = validateBox(game, location, candidateDigit);
            }
        }
    }

    return legal;
}

static cell getRow (cell location) {
    return (location / NUM_VALUES) * NUM_VALUES;
}

static cell getCol (cell location) {
    return location % NUM_VALUES;
}

static cell getBox (cell location) {
    cell box = MIN_CELL;
    box += ((getRow(location) / BOX_SIZE) * BOX_SIZE) * NUM_VALUES;
    box += (getCol(location) / BOX_SIZE) * BOX_SIZE;
    return box;
}

static int validateRow (SudukoGrid game, cell location, value candidateDigit) {
    int legal = TRUE;
    int i;
    cell pos;
    cell rowStart = getRow(location);

    for(i = 0; i < NUM_VALUES; i++) {
        pos = rowStart + i;

        if(getCell(game, pos) == candidateDigit) {
            legal = FALSE;
            break;
        }
    }
    return legal;
}

static int validateCol (SudukoGrid game, cell location, value candidateDigit) {
    int legal = TRUE;
    int i;
    cell colStart = getCol(location);
    cell locationInCol;

    for(i = 0; i < NUM_VALUES; i++) {
        locationInCol = colStart + (i * NUM_VALUES);

        if(getCell(game, locationInCol) == candidateDigit) {
            legal = FALSE;
            break;
        }
    }
    return legal;
}

static int validateBox (SudukoGrid game, cell location, value candidateDigit) {
    int legal = TRUE;
    int i, j;
    cell boxStart = getBox(location);
    cell locationInBox;

    for(i = 0; i < BOX_SIZE; i++) {
        for(j = 0; j < BOX_SIZE; j++) {
            locationInBox = boxStart + (i * NUM_VALUES) + j;

            if(getCell(game, locationInBox) == candidateDigit) {
                legal = FALSE;
                break;
            }
        }
    }
    return legal;
}