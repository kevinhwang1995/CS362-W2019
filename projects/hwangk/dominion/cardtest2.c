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
	testGame->whoseTurn = 0;
	testGame->deckCount[0] = 40;
	
	printf("Testing Smithy:\n");
	
	printf("Testing that Smithy draws 3 cards and that it discards the Smithy card: ");
	for(i = 0; i < 5; i++)
		testGame->hand[0][i] = cardsInHand[i];
	testGame->handCount[0] = 5;
	cardEffect(smithy, 0, 0, 0, testGame, 1, 0);
	myAssert(testGame->handCount[0], 7);

	printf("Testing that the card in the handPos that was previously Smithy is no longer Smithy: ");
	for(i = 0; i < 5; i++)
		testGame->hand[0][i] = cardsInHand[i];
	testGame->handCount[0] = 5;
	cardEffect(smithy, 0, 0, 0, testGame, 1, 0);
	myAssert(testGame->hand[0][1], !smithy);
	
	return 0;
}