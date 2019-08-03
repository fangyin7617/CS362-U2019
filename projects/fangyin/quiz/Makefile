CFLAGS= -Wall -fpic -coverage -lm -std=c99

testme.o: testme.c
	gcc -c testme.c -g  $(CFLAGS)
 
testme: testme.c testme.o
	gcc  -o testme -g  testme.o $(CFLAGS)
 
randomtest: testme
	./testme >> randomtest.out
	gcov -b -f testme.c >> randomtest.out

clean:
	rm -f *.gcov *.gcda *.gcno *.so *.o *.out testme testme.exe