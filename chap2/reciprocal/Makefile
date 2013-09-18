CC=gcc
CPP=g++
C_FLAGS=
CPP_FLAGS=
LIBS=

reciprocal: main.o reciprocal.o
	$(CPP) $(CFLAGS) -o reciprocal main.o reciprocal.o

main.o: main.c reciprocal.hpp
	$(CC) $(CFLAGS) -c main.c

reciprocal.o: reciprocal.cpp reciprocal.hpp
	$(CPP) $(CFLAGS) -c reciprocal.cpp

clean:
	rm -f *.o reciprocal
