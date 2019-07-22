/*
 * unittest2.c
 *

 */

/*
 * Include the following lines in your makefile:
 *
 * unittest2: unittest1.c dominion.o rngs.o
 *      gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
 */
 
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "minion"

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
  int xtraCoins = 0;
  int shuffledCards = 0;
  int choice1 = 0;
  int choice2 = 0;
  
  int handPos = 0;
  int seed = 1000;
  int numPlayers = 2;
  int currentPlayer  = 0;
  int nextPlayer = 1;
  
  struct gameState state, testc;
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
  
  initializeGame(numPlayers, k, seed, &state);
  
  printf("---------- Testing Card: %s ----------\n", TESTCARD);
  
  //---------- Test 1: choice1 = 1 = +2 coins ----------
  printf("Test 1: choice1 = 1 = +2 coins\n");
  
  memcpy(&testc, &state, sizeof(struct gameState));
  choice1 = 1;
  choice2 = 0;
  minionEffect(choice1, choice2, &state, currentPlayer, handPos);
  
  newCards = 0;
  xtraCoins = 2;
  
  
  printf("hand count = %d, expected = %d\n", testc.handCount[currentPlayer], state.handCount[currentPlayer] + newCards - discarded);
	printf("deck count = %d, expected = %d\n", testc.deckCount[currentPlayer], state.deckCount[currentPlayer] - newCards + shuffledCards);
  printf("numActions = %d, expected = %d\n", testc.numActions, state.numActions + 1);
	printf("coins = %d, expected = %d\n", testc.coins, state.coins + xtraCoins);
	assertPass(testc.handCount[currentPlayer], state.handCount[currentPlayer] + newCards - discarded);
	assertPass(testc.deckCount[currentPlayer],state.deckCount[currentPlayer] - newCards + shuffledCards);
  assertPass(testc.numActions, state.numActions + 1);
	assertPass(testc.coins, state.coins + xtraCoins);
 
 
  //---------- Test 2: choice2 = 1 = discard hand and +4 cards, then each player have over 4 cards and do the same action  ----------
  printf("Test 1: choice1 = 1 = discard hand and +4 cards, then each player have over 4 cards and do the same action\n");
  
  memcpy(&testc, &state, sizeof(struct gameState));
  choice1 = 0;
  choice2 = 1;
  
  for(int i = 0; i<4; i++){
    drawCard(currentPlayer, &testc);
    drawCard(nextPlayer, &testc);
  }
  
  newCards = 4;
  discarded = 0;
  
  minionEffect(choice1, choice2, &state, currentPlayer, handPos);
  
  printf("currentPlayer hand count = %d, expected = %d\n", testc.handCount[currentPlayer], state.handCount[currentPlayer] + newCards - discarded);
  printf("nextPlayer hand count = %d, expected = %d\n", testc.handCount[nextPlayer], state.handCount[nextPlayer] + newCards - discarded);
	printf("deck count = %d, expected = %d\n", testc.deckCount[currentPlayer], state.deckCount[currentPlayer] - newCards + shuffledCards);
  printf("numActions = %d, expected = %d\n", testc.numActions, state.numActions + 1);
	assertPass(testc.handCount[currentPlayer], state.handCount[currentPlayer] + newCards - discarded);
  assertPass(testc.handCount[nextPlayer], state.handCount[nextPlayer] + newCards - discarded);
	assertPass(testc.deckCount[currentPlayer],state.deckCount[currentPlayer] - newCards + shuffledCards);
  assertPass(testc.numActions, state.numActions + 1);
  
  printf("\n >>>>> Unit Test 5 SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);
  
  return 0;
}
 
 
 
 
 
 
 
 
 
 
 