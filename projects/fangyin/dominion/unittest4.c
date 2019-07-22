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
  int newCards = 0;
  int discarded = 1;
  int xtraCoins = 0;
  //int shuffledCards = 0;
  
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
  
  tributeEffect(&state, currentPlayer, nextPlayer, tributeRevealedCards);
  
  printf("numActions = %d, expected = %d\n", state.numActions, numActions);
  printf("currentPlayer hand count = %d, expected = %d\n", state.handCount[currentPlayer], state.handCount[currentPlayer] + newCards - discarded);
  
  assertPass(state.numActions, numActions);
  assertPass(state.handCount[currentPlayer], state.handCount[currentPlayer] + newCards - discarded + 1);
  
  //---------- Test 2: choice1 = 2 = 42 coins ----------
  printf("Test 2: choice1 = 1 = +4 coins\n");
  
  //memcpy(&testc, &state, sizeof(struct gameState));
  
  //state.deck[nextPlayer][state.deckCount[nextPlayer]-1] = baron;
  //state.deck[nextPlayer][state.deckCount[nextPlayer]-2] = minion;
  
  state.deckCount[nextPlayer] = 4;
	state.deck[nextPlayer][0] = gold;
	state.deck[nextPlayer][1] = gold;
	state.deck[nextPlayer][2] = gold;
  state.deck[nextPlayer][3] = gold;
  
  int coins = state.coins;
  
  tributeEffect(&state, currentPlayer, nextPlayer, tributeRevealedCards);
  xtraCoins = 4;
  
  printf("currentPlayer hand count = %d, expected = %d\n", state.handCount[currentPlayer], state.handCount[currentPlayer] + newCards - discarded);
  printf("coins = %d, expected = %d\n", state.coins, coins + xtraCoins);
  
  assertPass(state.handCount[currentPlayer], state.handCount[currentPlayer] + newCards - discarded + 1);
  assertPass(state.coins, coins + xtraCoins);
  
  
  //---------- Test 3: choice1 = 2 = +4 cards ----------
  printf("Test 3: choice1 = 1 = +4 cards\n");
  
  state.deckCount[nextPlayer] = 4;
	state.deck[nextPlayer][0] = duchy;
	state.deck[nextPlayer][1] = duchy;
	state.deck[nextPlayer][2] = duchy;
  state.deck[nextPlayer][3] = duchy;
  
  int cards = state.deckCount[currentPlayer];
  
  tributeEffect(&state, currentPlayer, nextPlayer, tributeRevealedCards);
  
  newCards = 4;
  
  printf("deckCount = %d, expected = %d\n", state.deckCount[currentPlayer] + 4, cards + newCards);
  
  assertPass(state.deckCount[currentPlayer] + 4, cards + newCards);
  
  return 0;
}
  