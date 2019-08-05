/*
 * randomtestcard2.c
 *
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TESTCARD "minion"

void assertPass(int result, int expected){
  if(result == expected){
    printf("\n >>>>> Failure! <<<<<\n\n");
  }
  else
    printf("\n >>>>> SUCCESS!! <<<<<\n\n");
}


int main(){
  struct gameState G, test;
  int k[10] = {adventurer, council_room, feast, gardens, mine,
            remodel, smithy, village, baron, great_hall};
  int n;
  int r;
  int seed;
  int numPlayers = 0;
  int currentPlayer  = 0;
  int handPos = 0;
  int choice1, choice2;
  srand(time(0));
  
  for(n = 0; n < 2000; n++){
    
    numPlayers = (rand() % 3) + 1;
    
    seed = (rand() % 1000) + 500;
    
    initializeGame(numPlayers, k, seed, &G);
    
    G.numPlayers = numPlayers;
    
    G.whoseTurn = rand() % G.numPlayers;
    
    currentPlayer = whoseTurn(&G);
    
    G.deckCount[currentPlayer] = rand() % MAX_DECK;
    
		G.discardCount[currentPlayer] = rand() % MAX_DECK;
   
		G.handCount[currentPlayer] = rand() % MAX_HAND;
   
    G.numActions = rand() % 3; 
    
    G.coins = rand() % 5; 
    
    memcpy(&test, &G, sizeof(struct gameState));
    
    printf("---------- Testing Card: %s ----------\n", TESTCARD);
    
    choice1 = rand() % 20;
    choice2 = rand() % 20;
    
    if(choice1 % 4 == 1 && choice2 % 4 == 0){
      r = Minion(choice1, choice2, &G, handPos, currentPlayer);
      printf("minion card return:\n");
      assertPass(r, 1);
      
      printf("Player choices 1\n");
      
      printf("deckCount test:\n");
      assertPass(G.deckCount[currentPlayer], test.deckCount[currentPlayer]);
      
      printf("discardCount test:\n");
      assertPass(G.discardCount[currentPlayer], test.discardCount[currentPlayer]);
      
      printf("handCount test:\n");
      assertPass(G.handCount[currentPlayer], test.handCount[currentPlayer]);
      
      printf("numActions test:\n");
      assertPass(G.numActions, test.numActions);
      
      printf("coins test:\n");
      assertPass(G.coins, test.coins);
      
      
    }
    else {
      Minion(choice1, choice2, &G, handPos, currentPlayer);
      
      printf("Player choices 2\n");
      
      printf("deckCount test:\n");
      assertPass(G.deckCount[currentPlayer], test.deckCount[currentPlayer]);
      
      printf("discardCount test:\n");
      assertPass(G.discardCount[currentPlayer], test.discardCount[currentPlayer]);
      
      printf("handCount test:\n");
      assertPass(G.handCount[currentPlayer], test.handCount[currentPlayer]);
      
      printf("numActions test:\n");
      assertPass(G.numActions, test.numActions);
      
      printf("coins test:\n");
      assertPass(G.coins, test.coins + 1);
    }
  }
  return 0;
}