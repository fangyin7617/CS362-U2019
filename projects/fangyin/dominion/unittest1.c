/*
 * unittest1.c
 *

 */

/*
 * Include the following lines in your makefile:
 *
 * unittest1: unittest1.c dominion.o rngs.o
 *      gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
 */
 
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "baron"

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
  
  int bonus = 0;
  int seed = 1000;
  int numPlayers = 2;
  int currentPlayer  = 0;
  
  struct gameState state, testc;
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
  
  initializeGame(numPlayers, k, seed, &state);
  
  printf("---------- Testing Card: %s ----------\n", TESTCARD);
  
  //---------- Test 1: choice1 = 1 = discard an Estate then +4 coins ----------
  printf("Test 1: choice1 = 1 = discard an Estate then +4 coins\n");
  
  memcpy(&testc, &state, sizeof(struct gameState));
  choice1 = 1;
  baronEffect(choice1, &state, currentPlayer, &bonus);
  
  newCards = 0;
  xtraCoins = 4;
  
  
  printf("hand count = %d, expected = %d\n", testc.handCount[currentPlayer], state.handCount[currentPlayer] + newCards - discarded);
	printf("deck count = %d, expected = %d\n", testc.deckCount[currentPlayer], state.deckCount[currentPlayer] - newCards + shuffledCards);
  printf("numBuys = %d, expected = %d\n", testc.numBuys, state.numBuys + 1);
	printf("coins = %d, expected = %d\n", testc.coins, state.coins + xtraCoins);
	assertPass(testc.handCount[currentPlayer], state.handCount[currentPlayer] + newCards - discarded);
	assertPass(testc.deckCount[currentPlayer],state.deckCount[currentPlayer] - newCards + shuffledCards);
  assertPass(testc.numBuys, state.numBuys + 1);
	assertPass(testc.coins, state.coins + xtraCoins);
  
  //---------- Test 2: choice1 = 0 = gain an estate ----------
  printf("Test 2: choice1 = 0 = gain an estate\n");
  
  memcpy(&testc, &state, sizeof(struct gameState));
  choice1 = 0;
  baronEffect(choice1, &state, currentPlayer, &bonus);
  
  newCards = 1;
  xtraCoins = 0;
  
  
  printf("hand count = %d, expected = %d\n", testc.handCount[currentPlayer], state.handCount[currentPlayer] + newCards - discarded);
	printf("deck count = %d, expected = %d\n", testc.deckCount[currentPlayer], state.deckCount[currentPlayer] - newCards + shuffledCards);
  printf("numBuys = %d, expected = %d\n", testc.numBuys, state.numBuys + 1);
  printf("estate = %d, expected = %d\n", testc.supplyCount[estate], state.supplyCount[estate] - 1);
	printf("coins = %d, expected = %d\n", testc.coins, state.coins + xtraCoins);
	assertPass(testc.handCount[currentPlayer], state.handCount[currentPlayer] + newCards - discarded);
	assertPass(testc.deckCount[currentPlayer], state.deckCount[currentPlayer] - newCards + shuffledCards);
  assertPass(testc.numBuys, state.numBuys + 1);
	assertPass(testc.coins, state.coins + xtraCoins);
  assertPass(testc.supplyCount[estate], state.supplyCount[estate] - 1);
  
  printf("\n >>>>> Unit Test 5 SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

	return 0;
 
 }
  
  