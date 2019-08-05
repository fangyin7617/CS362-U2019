/*
 * cardtest4.c
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "getWinners"

void assertPass(int result, int expected){
  if(result == expected){
    printf("\n >>>>> SUCCESS! <<<<<\n\n");
  }
  else
    printf("\n >>>>> Failure! <<<<<\n\n");
}

int main(){
  int seed = 1000;
  int numPlayers = 3;
  int players[3] = {1, 2, 3};
  struct gameState state;
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
  
  initializeGame(numPlayers, k, seed, &state);
  
  printf("---------- Testing Card: %s ----------\n", TESTCARD);
  
  //Test 1
  printf("Test 1: determine winner\n");
  //memcpy(&testc, &state, sizeof(struct gameState));
  players[0] = 1;
  players[1] = 3;
  players[2] = 5;
  
  getWinners(players, &state);
  
  printf("Player 1 = %d, Expected = %d\n", players[0], 1);
  printf("Player 2 = %d, Expected = %d\n", players[1], 0);
  printf("Player 3 = %d, Expected = %d\n", players[2], 0);
  
  assertPass(players[0], 1);
  assertPass(players[1], 0);
  assertPass(players[2], 0);
  
  
  //Test 2
  printf("Test 2: determine winner with card\n");
  
  for(int i = 0; i<4; i++){
    for(int j = 0; j<numPlayers; j++){
      state.hand[j][i] = duchy;
      state.hand[j][i] = estate;
      state.hand[j][i] = estate;
    }
  }
  
  getWinners(players, &state);
  
  printf("Player 1 should be winner\n");
  assertPass(players[0], 1);
  assertPass(players[1], 0);
  assertPass(players[2], 0);
  
  return 0;
  
}
    
    
    
    
  
  