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
	int testNumbers[28] = {0, 2, 5, 8, 0, 3, 6, 6, 5, 4, 4, 5, 4, 4, 3, 4, 3, 5, 3, 5, 3, 4, 2, 5, 4, 4, 4, -1};
	int testNames[28] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room,
						 feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion, steward,
				 		 tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map, 50};
	initializeGame(2, kCards, 1000, testGame);
	
	printf("Testing each card value with getCost (also tests invalid card name):\n");
	
	for(i = 0; i < 28; i++)
		myAssert(getCost(testNames[i]), testNumbers[i]); 
	
	return 0;
}