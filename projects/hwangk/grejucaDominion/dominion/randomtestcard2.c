#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int main()
{
	int i;
	int kCards[10] = {adventurer, smithy, village, council_room, feast, gardens, mine, remodel, baron, great_hall};
	int successfulTests = 0,
		failedTests = 0;
	int numTests = 100;
	
	for(i = 0; i < numTests; i++)
	{
		int numPlayers = rand() % 4,
			randSeed = rand();
		
		struct gameState* testGame = newGame();
		initializeGame(numPlayers, kCards, randSeed, testGame);
		
		testGame->deckCount[0] = rand() % MAX_DECK;
		testGame->discardCount[0] = rand() % MAX_DECK;
		testGame->handCount[0] = rand() % MAX_HAND;
		int compareHand = testGame->handCount[0];
		int currentActions = testGame->numActions;
		
		cardEffect(village, 0, 0, 0, testGame, 0, 0);
		
		if(testGame->numActions == currentActions + 2 && compareHand == testGame->handCount[0])
			successfulTests++;
		else
			failedTests++;
		
		free(testGame);
	}
	
	printf("Successful Tests(out of %d): %d\nFailed Tests(out of %d): %d\n", numTests, successfulTests, numTests, failedTests);
	
	return 0;
}