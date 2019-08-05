/*
 * unittest4.c
 *

 */

/*
 * Include the following lines in your makefile:
 *
 * unittest4: unittest1.c dominion.o rngs.o
 *      gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
 */
 
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "tribute"

void assertPass(int result, int expected){
  if(result == expected){
    printf("\n >>>>> SUCCESS! <<<<<\n\n");
  }
  else
    printf("\n >>>>> Failure! <<<<<\n\n");
}

int main(){
  int handPos = 0;
  
  int seed = 1000;
  int numPlayers = 2;
  int currentPlayer  = 0;
  int nextPlayer = 1;
  
  int tributeRevealedCards[2];
  
  struct gameState state;
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
  
  initializeGame(numPlayers, k, seed, &state);
  
  printf("---------- Testing Card: %s ----------\n", TESTCARD);
  
  //---------- Test 2: choice1 = 1 = +4 actions ----------
  printf("Test 1: choice1 = 1 = +4 actions\n");
  
  //memcpy(&testc, &state, sizeof(struct gameState));
  
  //state.deck[nextPlayer][state.deckCount[nextPlayer]-1] = baron;
  //state.deck[nextPlayer][state.deckCount[nextPlayer]-2] = minion;
  
  state.deckCount[nextPlayer] = 4;
	state.deck[nextPlayer][0] = baron;
	state.deck[nextPlayer][1] = baron;
	state.deck[nextPlayer][2] = baron;
  state.deck[nextPlayer][3] = baron;
  
  int numActions = state.numActions;
  int handc = state.handCount[currentPlayer];
  Tribute(currentPlayer, nextPlayer, tributeRevealedCards, &state, handPos);
  
  printf("numActions = %d, expected = %d\n", state.numActions, numActions + 4);
  printf("currentPlayer hand count = %d, expected = %d\n", state.handCount[currentPlayer], handc - 1);
  
  assertPass(state.numActions, numActions + 4);
  assertPass(state.handCount[currentPlayer], handc - 1);
  
  //---------- Test 2: choice2 = +4 coins ----------
  printf("Test 2: choice1 = 2 = +4 coins\n");
  
  //memcpy(&testc, &state, sizeof(struct gameState));
  
  //state.deck[nextPlayer][state.deckCount[nextPlayer]-1] = baron;
  //state.deck[nextPlayer][state.deckCount[nextPlayer]-2] = minion;
  
  state.deckCount[nextPlayer] = 4;
	state.deck[nextPlayer][0] = gold;
	state.deck[nextPlayer][1] = gold;
	state.deck[nextPlayer][2] = gold;
  state.deck[nextPlayer][3] = gold;
  
  int coins = state.coins;
  
  Tribute(currentPlayer, nextPlayer, tributeRevealedCards, &state, handPos);
  
  printf("currentPlayer hand count = %d, expected = %d\n", state.handCount[currentPlayer], state.handCount[currentPlayer]);
  printf("coins = %d, expected = %d\n", state.coins, coins + 4);
  
  assertPass(state.handCount[currentPlayer], state.handCount[currentPlayer]);
  assertPass(state.coins, coins + 4);
  
  
  //---------- Test 3: choice3 =  +4 cards ----------
  printf("Test 3: choice1 = 3 = +4 cards\n");
  
  state.deckCount[nextPlayer] = 4;
	state.deck[nextPlayer][0] = duchy;
	state.deck[nextPlayer][1] = duchy;
	state.deck[nextPlayer][2] = duchy;
  state.deck[nextPlayer][3] = duchy;
  
  int cards = state.deckCount[currentPlayer];
  
  Tribute(currentPlayer, nextPlayer, tributeRevealedCards, &state, handPos);
  
  
  printf("deckCount = %d, expected = %d\n", state.deckCount[currentPlayer], cards + 4);
  
  assertPass(state.deckCount[currentPlayer], cards + 4);
  
  return 0;
}
  