/*
 * cardtest1.c
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "initializeGame"

void assertPass(int result, int expected){
  if(result == expected){
    printf("\n >>>>> SUCCESS! <<<<<\n\n");
  }
  else
    printf("\n >>>>> Failure! <<<<<\n\n");
}

int main(){
  int seed = 1000;
  int numPlayers = 0;
  struct gameState state;
  
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
  
  //initializeGame(numPlayers, k, seed, &state);
  
  printf("---------- Testing Card: %s ----------\n", TESTCARD);
  
  //Test 1
  printf("Test 1: numPlayers = 2\n");
  numPlayers = 2;
  initializeGame(numPlayers, k, seed, &state);
  
  printf("curse = %d, expected = %d\n", state.supplyCount[curse], 10);
  printf("estate = %d, expected = %d\n", state.supplyCount[estate], 8);
  printf("duchy = %d, expected = %d\n", state.supplyCount[duchy], 8);
  printf("province = %d, expected = %d\n", state.supplyCount[province], 8);
  printf("copper = %d, expected = %d\n", state.supplyCount[copper], 60 - (7*numPlayers));
  printf("silver = %d, expected = %d\n", state.supplyCount[silver], 40);
  printf("gold = %d, expected = %d\n", state.supplyCount[gold], 30);
  
  assertPass(state.supplyCount[curse], 10);
  assertPass(state.supplyCount[estate], 8);
  assertPass(state.supplyCount[duchy], 8);
  assertPass(state.supplyCount[province], 8);
  assertPass(state.supplyCount[copper], 60 - (7*numPlayers));
  assertPass(state.supplyCount[silver], 40);
  assertPass(state.supplyCount[gold], 30);
  
 
  assertPass(state.outpostPlayed, 0);
  assertPass(state.phase, 0);
  assertPass(state.numActions, 1);
  assertPass(state.numBuys, 1);
  assertPass(state.playedCardCount, 0);
  assertPass(state.whoseTurn, 0);
  assertPass(state.handCount[0], 5);
  
  for (int i = adventurer; i <= treasure_map; i++){      	
    for (int j=0; j < 10; j++){      	
      if(k[j] == i){
        if (k[i] == great_hall || k[i] == gardens){
          if(numPlayers == 2){
            assertPass(state.supplyCount[i], 10);
          }
          else
            assertPass(state.supplyCount[i], 8);
        }
      }
    }
  }
  
  //Test 2
  printf("Test 2: numPlayers = 3\n");
  numPlayers = 3;
  initializeGame(numPlayers, k, seed, &state);
  
  printf("curse = %d, expected = %d\n", state.supplyCount[curse], 20);
  printf("estate = %d, expected = %d\n", state.supplyCount[estate], 12);
  printf("duchy = %d, expected = %d\n", state.supplyCount[duchy], 12);
  printf("province = %d, expected = %d\n", state.supplyCount[province], 12);
  printf("copper = %d, expected = %d\n", state.supplyCount[copper], 60 - (7*numPlayers));
  printf("silver = %d, expected = %d\n", state.supplyCount[silver], 40);
  printf("gold = %d, expected = %d\n", state.supplyCount[gold], 30);
  
  assertPass(state.supplyCount[curse], 20);
  assertPass(state.supplyCount[estate], 12);
  assertPass(state.supplyCount[duchy], 12);
  assertPass(state.supplyCount[province], 12);
  assertPass(state.supplyCount[copper], 60 - (7*numPlayers));
  assertPass(state.supplyCount[silver], 40);
  assertPass(state.supplyCount[gold], 30);
  
 
  assertPass(state.outpostPlayed, 0);
  assertPass(state.phase, 0);
  assertPass(state.numActions, 1);
  assertPass(state.numBuys, 1);
  assertPass(state.playedCardCount, 0);
  assertPass(state.whoseTurn, 0);
  assertPass(state.handCount[0], 5);
  
  for (int i = adventurer; i <= treasure_map; i++){      	
    for (int j=0; j < 10; j++){      	
      if(k[j] == i){
        if (k[i] == great_hall || k[i] == gardens){
          if(numPlayers == 2){
            assertPass(state.supplyCount[i], 8);
          }
          else
            assertPass(state.supplyCount[i], 10);
        }
      }
    }
  }
  
  //Test 3
  printf("Test 3: numPlayers = 1\n");
  numPlayers = 1;
  int value = initializeGame(numPlayers, k, seed, &state);
  assertPass(value, -1);
  
  return 0;
}
  
  
  