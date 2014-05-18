#include <stdio.h>
#include <assert.h>
#include "SudukoGrid.h"

static void clearGame (SudukoGrid game);
static void testClearGame ();
static void testGetSetCell ();
static void testIsFullFreeCell ();
//static void testFullGrid (sudukoGrid game);
static void testIsLegal ();

void testSudukoGrid () {
    SudukoGrid game1 = newSudukoGrid();

    printf ("testing SudukoGrid.c... \n");

    testClearGame ();
    testGetSetCell ();
    testIsFullFreeCell ();
    testIsLegal();

    clearGame(game1);
    showGame(game1);

    printf ("All passed!\n");
}

static void clearGame (SudukoGrid game) {
}

static void testClearGame () {

}

static void testGetSetCell () {

}

static void testIsFullFreeCell () {

}

static void testIsLegal () {

}