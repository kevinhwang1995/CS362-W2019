#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>

void myAssert(int a, int b)
{
	if(a == b)
		printf("PASS\n");
	else
		printf("FAIL\n");
}

int main()
{
	int i;
	struct gameState* testGame = newGame();
	int kCards[10] = {adventurer, smithy, village, great_hall, steward, council_room, feast, gardens, mine, remodel};	
	int cardsInHand[5] = {adventurer, smithy, steward, gardens, remodel};
	initializeGame(2, kCards, 1000, testGame);
	
	printf("Testing handCard with a hand of five cards:\n");
	
	for(i = 0; i < 5; i++)
		testGame->hand[0][i] = cardsInHand[i];

	testGame->whoseTurn = 0;
	
	for(i = 0; i < 5; i++)
	{
		printf("Card %d: ", i + 1);
		myAssert(handCard(i, testGame), cardsInHand[i]);
	}
	
	return 0;
}