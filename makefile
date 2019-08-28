CPPFLAGS=  -Wall -Wextra -pedantic -ldl

all:	Test

Test:	test.o
				g++ $(CPPFLAGS) test.o -o DequeTest

test.o:	test.cpp
				g++ -c $(CPPFLAGS) test.cpp

run:
				time -p ./DequeTest

checkmem:
				valgrind --tool=memcheck --leak-check=yes ./DequeTest

clean:
				rm -f *.o DequeTest
