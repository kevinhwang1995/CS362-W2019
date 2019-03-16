CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

unittestresults: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.o rngs.o
	echo "Results for running Unit Tests:" >> unittestresults.out
	echo "unittest1.c:" >> unittestresults.out
	gcc -o unittest1 -g dominion.o rngs.o unittest1.c -lm $(CFLAGS)
	./unittest1 >> unittestresults.out
	
	echo "unittest2.c:" >> unittestresults.out
	gcc -o unittest2 -g dominion.o rngs.o unittest2.c -lm $(CFLAGS)
	./unittest2 >> unittestresults.out
	
	echo "unittest3.c:" >> unittestresults.out
	gcc -o unittest3 -g dominion.o rngs.o unittest3.c -lm $(CFLAGS)
	./unittest3 >> unittestresults.out

	echo "unittest4.c:" >> unittestresults.out
	gcc -o unittest4 -g dominion.o rngs.o unittest4.c -lm $(CFLAGS)
	./unittest4 >> unittestresults.out
	
	echo "cardtest1.c:" >> unittestresults.out
	gcc -o cardtest1 -g dominion.o rngs.o cardtest1.c -lm $(CFLAGS)
	./cardtest1 >> unittestresults.out

	echo "cardtest2.c:" >> unittestresults.out
	gcc -o cardtest2 -g dominion.o rngs.o cardtest2.c -lm $(CFLAGS)
	./cardtest2 >> unittestresults.out
	
	echo "cardtest3.c:" >> unittestresults.out
	gcc -o cardtest3 -g dominion.o rngs.o cardtest3.c -lm $(CFLAGS)
	./cardtest3 >> unittestresults.out
	
	echo "cardtest4.c:" >> unittestresults.out
	gcc -o cardtest4 -g dominion.o rngs.o cardtest4.c -lm $(CFLAGS)
	./cardtest4 >> unittestresults.out
	
	gcov -c -b -f dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	
randomtestcard1: randomtestcard1.c dominion.o rngs.o
	echo "Results for running randomtestcard1:" >> randomtestcard1.out
	gcc -o randomtestcard1 -g dominion.o rngs.o randomtestcard1.c -lm $(CFLAGS)
	./randomtestcard1 >> randomtestcard1.out
	gcov -c -b -f dominion.c >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out
	
randomtestcard2: randomtestcard2.c dominion.o rngs.o
	echo "Results for running randomtestcard2:" >> randomtestcard2.out
	gcc -o randomtestcard2 -g dominion.o rngs.o randomtestcard2.c -lm $(CFLAGS)
	./randomtestcard2 >> randomtestcard2.out
	gcov -c -b -f dominion.c >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	echo "Results for running randomtestadventurer:" >> randomtestadventurer.out
	gcc -o randomtestadventurer -g dominion.o rngs.o randomtestadventurer.c -lm $(CFLAGS)
	./randomtestadventurer >> randomtestadventurer.out
	gcov -c -b -f dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out
	
runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player cardtest1 cardtest2 cardtest3 cardtest4 unittest1 unittest2 unittest3 unittest4 randomtestcard1 randomtestcard2 randomtestadventurer player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
