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
	int cardsInHand[5] = {adventurer, smithy, village, gardens, remodel};
	initializeGame(2, kCards, 1000, testGame);
	testGame->whoseTurn = 0;
	testGame->deckCount[0] = 40;
	
	printf("Testing Village:\n");
	
	printf("Testing that Village draws one card: ");
	for(i = 0; i < 5; i++)
		testGame->hand[0][i] = cardsInHand[i];
	testGame->handCount[0] = 5;
	cardEffect(village, 0, 0, 0, testGame, 2, 0);
	myAssert(testGame->handCount[0], 5);
	
	printf("Testing that Village adds two actions: ");
	testGame->numActions = 1;
	for(i = 0; i < 5; i++)
		testGame->hand[0][i] = cardsInHand[i];
	testGame->handCount[0] = 5;
	cardEffect(village, 0, 0, 0, testGame, 2, 0);
	myAssert(testGame->numActions, 3);
	
	printf("Testing that Village discards the Village card when played: ");
	for(i = 0; i < 5; i++)
		testGame->hand[0][i] = cardsInHand[i];
	testGame->handCount[0] = 5;
	cardEffect(village, 0, 0, 0, testGame, 2, 0);
	myAssert(testGame->hand[0][2], !village);

	return 0;
}