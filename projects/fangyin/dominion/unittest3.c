/*
 * unittest3.c
 *

 */

/*
 * Include the following lines in your makefile:
 *
 * unittest3: unittest1.c dominion.o rngs.o
 *      gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
 */
 
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTARD "ambassador"

void assertPass(int result, int expected){
  if(result == expected){
    printf("\n >>>>> SUCCESS! <<<<<\n\n");
  }
  else
    printf("\n >>>>> Failure! <<<<<\n\n");
}

int main(){
  int choice1 = 0;
  int choice2 = 0;
  
  int handPos = 0;
  int seed = 1000;
  int numPlayers = 2;
  int currentPlayer  = 0;
  
  struct gameState state;
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
  
  initializeGame(numPlayers, k, seed, &state);
  
  printf("---------- Testing Card: %s ----------\n", TESTARD);
  
  state.handCount[currentPlayer] = 3;
	state.hand[currentPlayer][0] = copper;
	state.hand[currentPlayer][1] = silver;
	state.hand[currentPlayer][2] = silver;
 
  state.handCount[currentPlayer+1] = 3;
	state.hand[currentPlayer+1][0] = copper;
	state.hand[currentPlayer+1][1] = silver;
	state.hand[currentPlayer+1][2] = gold;
  
  //---------- Test 1: choice1 = 1 = +2 coins ----------
  printf("Test 1: choice1 2 copies\n");
  choice1 = 1;
  choice2 = 2;
  int silvern = state.supplyCount[silver];
  
  int handstate = state.handCount[currentPlayer];
  int handstatenext = state.handCount[currentPlayer+1];
  //int ambassadorCardEffect(struct gameState *state, int currentPlayer, int choice1, int choice2, int handPos);
  int value = ambassadorEffect(choice1, choice2, &state, currentPlayer, handPos);
  
  
  printf("currentPlayer hand count = %d, expected = %d\n", state.handCount[currentPlayer], handstate);
  printf("nextPlayer hand count = %d, expected = %d\n", state.handCount[currentPlayer+1], handstatenext);
  printf("supplyCount[silver] = %d, expected = %d\n", state.supplyCount[silver], silvern + 2);
  
  assertPass(state.handCount[currentPlayer], handstate);
  assertPass(state.handCount[currentPlayer+1], handstatenext);
  assertPass(state.supplyCount[silver], silvern + 2);
  assertPass(value, 0);
 

  printf("\n >>>>> Unit Test 3 SUCCESS: Testing complete %s <<<<<\n\n", TESTARD);
  
  return 0;
}
 
 