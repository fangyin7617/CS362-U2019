/*
 * cardtest3.c
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "endTurn"

void assertPass(int result, int expected){
  if(result == expected){
    printf("\n >>>>> SUCCESS! <<<<<\n\n");
  }
  else
    printf("\n >>>>> Failure! <<<<<\n\n");
}

int main(){
  int seed = 1000;
  int numPlayers = 2;
  int currentPlayer = 0;
  int value = 0;
  struct gameState state, testc;
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
  
  initializeGame(numPlayers, k, seed, &state);
  
  printf("---------- Testing Card: %s ----------\n", TESTCARD);
  
  //Test 1
  printf("Test 1: check variables\n");
  memcpy(&testc, &state, sizeof(struct gameState));
  value = endTurn(&testc);
  
  printf("outpostPlayed = %d, Expected = %d\n", testc.outpostPlayed, 0);
  printf("phase = %d, Expected = %d\n", testc.phase, 0);
  printf("numActions = %d, Expected = %d\n", testc.numActions, 1);
  printf("coins = %d, Expected = %d\n", testc.coins, 0);
  printf("numBuys = %d, Expected = %d\n", testc.numBuys, 1);
  printf("playedCardCount = %d, Expected = %d\n", testc.playedCardCount, 0);
  
  assertPass(testc.outpostPlayed, 0);
  assertPass(testc.phase, 0);
  assertPass(testc.numActions, 1);
  assertPass(testc.coins, 0);
  assertPass(testc.numBuys, 1);
  assertPass(testc.playedCardCount, 0);
  assertPass(value, 0);
  
  //Test 2
  printf("Test 2: check hand\n");
  memcpy(&testc, &state, sizeof(struct gameState));
  endTurn(&testc);
  printf("currentPlayer hand = %d, Expected = %d\n", testc.handCount[currentPlayer], 0);
  printf("whoseTurn hand = %d, Expected = %d\n", testc.handCount[currentPlayer+1], 5);
  
  assertPass(testc.handCount[currentPlayer], 0);
  assertPass(testc.handCount[currentPlayer+1], 5);
  
  return 0;
  
}
  
  
  
  
  
  
  
  