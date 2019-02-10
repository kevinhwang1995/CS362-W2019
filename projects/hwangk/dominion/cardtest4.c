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
	int kCards[10] = {adventurer, smithy, village, great_hall, steward, council_room, feast, outpost, mine, remodel};	
	int cardsInHand[5] = {adventurer, smithy, steward, outpost, remodel};
	initializeGame(2, kCards, 1000, testGame);
	testGame->whoseTurn = 0;
	testGame->deckCount[0] = 40;
	
	printf("Testing Outpost:\n");
	
	printf("Testing that Outpost sets the outpost flag: ");
	for(i = 0; i < 5; i++)
		testGame->hand[0][i] = cardsInHand[i];
	testGame->handCount[0] = 5;
	cardEffect(outpost, 0, 0, 0, testGame, 3, 0);
	myAssert(testGame->outpostPlayed, 1);

	printf("Testing that the handPos that was once outpost is no longer outpost: ");
	for(i = 0; i < 5; i++)
		testGame->hand[0][i] = cardsInHand[i];
	testGame->handCount[0] = 5;
	cardEffect(outpost, 0, 0, 0, testGame, 3, 0);
	myAssert(testGame->hand[0][3], remodel);
	
	printf("Testing that the outpost card is discarded when played: ");
	for(i = 0; i < 5; i++)
		testGame->hand[0][i] = cardsInHand[i];
	testGame->handCount[0] = 5;
	cardEffect(outpost, 0, 0, 0, testGame, 3, 0);
	myAssert(testGame->handCount[0], 4);
	
	return 0;
}