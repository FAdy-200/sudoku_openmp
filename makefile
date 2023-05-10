CC=g++
MAINTARGET = main
TESTTARGET = unittest
LIB = lib

OBJS = \
	$(LIB)/helpers.o 

HDS = \
 	$(LIB)/helpers.hpp

DEPS = $(HDS)

MAINOBJ= $(MAINTARGET).o $(OBJS)

TESTOBJ= $(TESTTARGET).o $(OBJS)

CFLAGS= -fopenmp -O3

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $< 

test: $(TESTOBJ)
	$(CC) $(CFLAGS) -o $(TESTTARGET).run $^
	./$(TESTTARGET).run 

main: $(MAINOBJ)
	$(CC) $(CFLAGS) -o $(MAINTARGET).run $^

run:
	main
	./$(MAINTARGET).run

clean:
	rm -f */*.o *.o */*.run *.run