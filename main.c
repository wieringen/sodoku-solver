#include <stdio.h>
#include "SudukoGrid.h"
#include "testSudukoGrid.h"

int hasSolution(SudukoGrid game);

int main (int argc, const char *argv[]) {

    testSudukoGrid();

    SudukoGrid sample = newSudukoGrid();
    readGame (sample);

    printf("Problem:\n");
    showGame (sample);
    if (hasSolution(sample)) {
        printf("\nSolution:\n");
        showGame (sample);
    }

    return 0;
}

int hasSolution(SudukoGrid game) {
    int solved;
    cell candidateCell;
    value trialValue;

    if (isFull (game)) {
        solved = TRUE;
    } else {
        candidateCell = getFreeCell (game);
        trialValue = MIN_VALUE;
        solved = FALSE;

        while (!solved && trialValue <= MAX_VALUE) {

            if (isLegal (game, candidateCell, trialValue)) {
                setCell (game, candidateCell, trialValue);

                if(hasSolution(game)) {
                    solved = TRUE;
                }
                else {
                    clearCell (game, candidateCell);
                }
            }
            trialValue++;
        }
    }

    return solved;
}