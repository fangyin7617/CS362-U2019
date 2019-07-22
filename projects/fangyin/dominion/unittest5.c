/*
 * unittest5.c
 *

 */

/*
 * Include the following lines in your makefile:
 *
 * unittest2: unittest5.c dominion.o rngs.o
 *      gcc -o unittest5 -g  unittest5.c dominion.o rngs.o $(CFLAGS)
 */
 
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "mine"

void assertPass(int result, int expected){
  if(result == expected){
    printf("\n >>>>> SUCCESS! <<<<<\n\n");
  }
  else
    printf("\n >>>>> Failure! <<<<<\n\n");
}

int main(){
  int newCards = 0;
  int discarded = 1;
  //int shuffledCards = 0;
  int choice1 = 0;
  int choice2 = 0;
  int handstate = 0;
  int handPos = 0;
  int seed = 1000;
  int numPlayers = 2;
  int currentPlayer  = 0;
  int nextPlayer = 1;
  
  struct gameState state;
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
  
  initializeGame(numPlayers, k, seed, &state);
  
  printf("---------- Testing Card: %s ----------\n", TESTCARD);
  
  //---------- Test 1: choice1 = 1 = +2 coins ----------
  printf("Test 1: choice1 choose a treasure");
  
  //memcpy(&testc, &state, sizeof(struct gameState));
  
  state.handCount[currentPlayer] = 3;
	state.hand[currentPlayer][0] = copper;
	state.hand[currentPlayer][1] = silver;
	state.hand[currentPlayer][2] = gold;
  
  handstate = state.handCount[currentPlayer];
  choice1 = 1;
  
  int mineCardEffect(struct gameState *state, int currentPlayer, int choice1, int choice2, int handPos);
  mineEffect(choice1, choice2, &state, currentPlayer, handPos, nextPlayer);
  
  newCards = 1;
  
  printf("hand count = %d, expected = %d\n", state.handCount[currentPlayer], handstate + newCards - discarded);
  assertPass(state.handCount[currentPlayer], handstate + newCards - discarded);
  
  return 0;
  
}
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  