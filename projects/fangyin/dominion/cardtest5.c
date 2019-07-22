/*
 * cardtest5.c
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "drawCard"

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
  struct gameState state;
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
  
  initializeGame(numPlayers, k, seed, &state);
  
  printf("---------- Testing Card: %s ----------\n", TESTCARD);
  
  //Test 1
  printf("Test 1: deckCount = 0\n");
  state.deckCount[currentPlayer] = 0;
  
  drawCard(currentPlayer, &state);
  for(int i = 0; i < state.discardCount[currentPlayer]; i++){
    assertPass(state.deck[currentPlayer][i], state.discard[currentPlayer][i]);
  }
  
  printf("discardCount = %d, Expected = %d\n", state.discardCount[currentPlayer], 0);
  printf("deckCount = %d, Expected = %d\n", state.deckCount[currentPlayer], state.discardCount[currentPlayer]);
  
  assertPass(state.discardCount[currentPlayer], 0);
  assertPass(state.deckCount[currentPlayer], state.discardCount[currentPlayer]);
  
  
  //Test 2
   printf("Test 2: deckCount != 0\n");
   state.deckCount[currentPlayer] = 8;
   drawCard(currentPlayer, &state);
   
   int count = state.handCount[currentPlayer];//Get current hand count for player
   int deckCounter;
   deckCounter = state.deckCount[currentPlayer];
   
   printf("hand = %d, Expected = %d\n", state.hand[currentPlayer][count] + 4, state.deck[currentPlayer][deckCounter - 1]);
   assertPass(state.hand[currentPlayer][count] + 4, state.deck[currentPlayer][deckCounter - 1]);
   
   return 0;
   
}
   
   
   
  
  

  