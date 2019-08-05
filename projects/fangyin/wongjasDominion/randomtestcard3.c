/*
 * randomtestcard3.c
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

#define TESTCARD "tribute"

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
  int n, i;
  int choice;
  int seed;
  int numPlayers = 0;
  int currentPlayer  = 0;
  int nextPlayer = 0;
  int handPos = 0;
  int tributeRevealedCards[2];
  srand(time(0));
  
  for(n = 0; n < 2000; n++){
    
    numPlayers = (rand() % 2) + 2;
    
    seed = (rand() % 1000) + 500;
    
    initializeGame(numPlayers, k, seed, &G);
    
    G.numPlayers = numPlayers;
    
    G.whoseTurn = rand() % G.numPlayers;
    
    currentPlayer = whoseTurn(&G);
    
    nextPlayer = currentPlayer + 1;
    
    G.deckCount[currentPlayer] = rand() % MAX_DECK;
    
		G.discardCount[currentPlayer] = rand() % MAX_DECK;
   
		G.handCount[currentPlayer] = rand() % MAX_HAND;
   
    G.deckCount[nextPlayer] = rand() % MAX_DECK;
    
		G.discardCount[nextPlayer] = rand() % MAX_DECK;
   
		G.handCount[nextPlayer] = rand() % MAX_HAND;
   
    G.numActions = rand() % 3; 
    
    G.coins = rand() % 5; 
    
    choice = rand() % 20;
    
    
    for(i = 0; i < G.deckCount[nextPlayer]; i++){
      if(choice % 3 == 1){
        G.discard[nextPlayer][i] = baron;
      }
      else if(choice % 3 == 2){
        G.discard[nextPlayer][i] = gold;
      }
      else
        G.discard[nextPlayer][i] = estate;
    }
    
    memcpy(&test, &G, sizeof(struct gameState));
    
    printf("---------- Testing Card: %s ----------\n", TESTCARD);
    
    
    if(choice % 3 == 1 ){
      Tribute(currentPlayer, nextPlayer, tributeRevealedCards, &G, handPos);
      
      printf("test 1\n");
      
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
    else if(choice % 3 == 2 ){
      Tribute(currentPlayer, nextPlayer, tributeRevealedCards, &G, handPos);
     
      printf("test 2\n");
      
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
    else{
      Tribute(currentPlayer, nextPlayer, tributeRevealedCards, &G, handPos);
      
      printf("test 3\n");
      
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
   }
  return 0;
}