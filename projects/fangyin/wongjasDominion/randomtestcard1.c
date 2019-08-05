/*
 * randomtestcard1.c
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

#define TESTCARD "baron"

void assertPass(int result, int expected){
  if(result == expected){
    printf("\n >>>>> Failure! <<<<<\n\n");
  }
  else
    printf("\n >>>>> SUCCESS!! <<<<<\n\n");
}


int main(){
  struct gameState G, test;
  srand(time(0));
  int n, i;
  int r;
  int numPlayers = 0;
  int currentPlayer  = 0;
  int choice;
  
  for(n = 0; n < 20000; n++){
    for(i = 0; i < sizeof(struct gameState); i++){
      ((char*)&G)[i] = floor(Random() * 256);
    }
    numPlayers = (rand() % 3) + 1;
    G.numPlayers = numPlayers;
    G.whoseTurn = rand() % G.numPlayers;
    currentPlayer = whoseTurn(&G);
    G.deckCount[currentPlayer] = rand() % MAX_DECK;
		G.discardCount[currentPlayer] = rand() % MAX_DECK;
		G.handCount[currentPlayer] = rand() % MAX_HAND;
    G.supplyCount[estate] = rand() % 10;
    G.numBuys = 0;
    
    for(i = 0; i < G.handCount[currentPlayer]; i++){
      G.hand[currentPlayer][i] = estate;
    }
    
    memcpy(&test, &G, sizeof(struct gameState));
    
    printf("---------- Testing Card: %s ----------\n", TESTCARD);
    
    choice = rand() % 20;
    
    if(choice % 4 == 0){
      r = Baron(choice, &G, currentPlayer);
      printf("baron card return:\n");
      assertPass(r, 1);
      
    }
    else{
      r = Baron(choice, &G, currentPlayer);
      printf("deckCount test:\n");
      assertPass(G.deckCount[currentPlayer], test.deckCount[currentPlayer]);
      printf("discardCount test:\n");
      assertPass(G.discardCount[currentPlayer], test.discardCount[currentPlayer]);
      printf("handCount test:\n");
      assertPass(G.handCount[currentPlayer], test.handCount[currentPlayer]);
      printf("numBuys test:\n");
      assertPass(G.numBuys, test.numBuys);
      printf("supplyCount test:\n");
      assertPass(G.supplyCount[currentPlayer], test.supplyCount[currentPlayer]);
    }
  }
  return 0;
}
      
      
      
      
      
      
      
      
      
   
    
    