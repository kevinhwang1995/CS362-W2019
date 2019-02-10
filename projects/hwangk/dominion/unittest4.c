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
	struct gameState* testGame2p = newGame();
	struct gameState* testGame3p = newGame();
	struct gameState* testGame4p = newGame();
	int kCards[10] = {adventurer, smithy, village, great_hall, steward, council_room, feast, gardens, mine, remodel};	
	initializeGame(2, kCards, 1000, testGame2p);
	initializeGame(3, kCards, 1000, testGame3p);
	initializeGame(4, kCards, 1000, testGame4p);
	
	printf("Testing supplyCount with a newly initialized gamestate:\n");
	
	printf("Testing supplyCount with Curse card and two players: ");
	myAssert(supplyCount(curse, testGame2p), 10);
	
	printf("Testing supplyCount with Estate card and two players: ");
	myAssert(supplyCount(estate, testGame2p), 8);
	
	printf("Testing supplyCount with Duchy card and two players: ");
	myAssert(supplyCount(duchy, testGame2p), 8);
	
	printf("Testing supplyCount with Province card and two players: ");
	myAssert(supplyCount(province, testGame2p), 8);	
	
	printf("Testing supplyCount with Curse card and three players: ");
	myAssert(supplyCount(curse, testGame3p), 20);
	
	printf("Testing supplyCount with Estate card and three players: ");
	myAssert(supplyCount(estate, testGame3p), 12);
	
	printf("Testing supplyCount with Duchy card and three players: ");
	myAssert(supplyCount(duchy, testGame3p), 12);
	
	printf("Testing supplyCount with Province card and three players: ");
	myAssert(supplyCount(province, testGame3p), 12);	

	printf("Testing supplyCount with Curse card and four players: ");
	myAssert(supplyCount(curse, testGame4p), 30);
	
	printf("Testing supplyCount with Estate card and four players: ");
	myAssert(supplyCount(estate, testGame4p), 12);
	
	printf("Testing supplyCount with Duchy card and four players: ");
	myAssert(supplyCount(duchy, testGame4p), 12);
	
	printf("Testing supplyCount with Province card and four players: ");
	myAssert(supplyCount(province, testGame4p), 12);	
	
	return 0;
}