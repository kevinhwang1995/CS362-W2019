#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
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
	struct gameState* testGame = newGame();
	int i;
	int kCards[10] = {adventurer, smithy, village, great_hall, steward, council_room, feast, gardens, mine, remodel};	
	int testNumbers[5] = {0, 5, 10, 15, 2};
	int noTreasure[5] = {adventurer, smithy, steward, gardens, remodel};
	int allCopper[5] = {copper, copper, copper, copper, copper};
	int allSilver[5] = {silver, silver, silver, silver, silver};
	int allGold[5] = {gold, gold, gold, gold, gold};
	initializeGame(2, kCards, 1000, testGame);
	testGame->handCount[0] = 5;
	testGame->whoseTurn = 0;
	printf("Testing updateCoins:\n");
	
	printf("Testing with no treasure cards and no bonus: ");
	for(i = 0; i < 5; i++)
		testGame->hand[0][i] = noTreasure[i];
	updateCoins(0, testGame, 0);
	myAssert(testGame->coins, testNumbers[0]);
	
	printf("Testing with a hand of five coppers: ");
	for(i = 0; i < 5; i++)
		testGame->hand[0][i] = allCopper[i];
	updateCoins(0, testGame, 0);
	myAssert(testGame->coins, testNumbers[1]);
	
	printf("Testing with a hand of five silvers: ");
	for(i = 0; i < 5; i++)
		testGame->hand[0][i] = allSilver[i];
	updateCoins(0, testGame, 0);
	myAssert(testGame->coins, testNumbers[2]);

	printf("Testing with a hand of five golds: ");
	for(i = 0; i < 5; i++)
		testGame->hand[0][i] = allGold[i];
	updateCoins(0, testGame, 0);
	myAssert(testGame->coins, testNumbers[3]);

	printf("Testing with no treasure cards and a bonus of 2: ");
	for(i = 0; i < 5; i++)
		testGame->hand[0][i] = noTreasure[i];
	updateCoins(0, testGame, 2);
	myAssert(testGame->coins, testNumbers[4]);
		
	return 0;
}