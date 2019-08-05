#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "shuffle"

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
  printf("Test 1: deckCount not cahnge\n");
  memcpy(&testc, &state, sizeof(struct gameState));
  shuffle(currentPlayer, &testc);
  
  for(int i = 0; i < testc.deckCount[currentPlayer]; i++) {
    if(testc.deck[currentPlayer][i] == state.deck[currentPlayer][i]) {
      value = 1;
    }
  }
  
  printf("Original deckCount = %d, After shuffle = %d\n", state.deckCount[currentPlayer], testc.deckCount[currentPlayer]);
  assertPass(value, 1);

  //Test 2
  printf("Test 2: deckCount = 0\n");
  memcpy(&testc, &state, sizeof(struct gameState));
  testc.deckCount[currentPlayer] = 0;
  value = shuffle(currentPlayer, &testc);
  
  printf("Original deckCount = %d, After shuffle = %d\n", state.deckCount[currentPlayer], testc.deckCount[currentPlayer]);
  assertPass(value, -1);
  
  
  return 0;

}
  






