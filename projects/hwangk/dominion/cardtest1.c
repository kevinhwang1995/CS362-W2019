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
	
	printf("Testing Adventurer:\n");
	
	printf("Testing when a player's deck is empty and needs to be reshuffled: ");
	testGame->deckCount[0] = 0;
	cardEffect(adventurer, 0, 0, 0, testGame, 0, 0);
	myAssert(1, (testGame->deckCount[0] > 0));
	
	printf("Testing handCount after playing Adventurer: ");
	testGame->deckCount[0] = 40;
	testGame->handCount[0] = 5;
	cardEffect(adventurer, 0, 0, 0, testGame, 0, 0);
	myAssert(6, testGame->handCount[0]);			
	
	printf("Testing to make sure two treasure cards are drawn: ");
	testGame->handCount[0] = 5;
	for(i = 0; i < 5; i++)
		testGame->hand[0][i] = cardsInHand[i];
	cardEffect(adventurer, 0, 0, 0, testGame, 0, 0);
	myAssert((testGame->hand[0][4] == copper || silver || gold) && (testGame->hand[0][5] == copper || silver || gold), 1);
	
	printf("Testing to make sure all excess cards are discarded: ");
	testGame->handCount[0] = 5;
	for(i = 0; i < 5; i++)
		testGame->hand[0][i] = cardsInHand[i];
	cardEffect(adventurer, 0, 0, 0, testGame, 0, 0);
	myAssert(testGame->handCount[0], 6);

	return 0;
}