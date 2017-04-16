CC=g++
CFLAGS=-std=gnu++0x -c -Wall

all: kk

randints: randints.o
	$(CC) randints.o -o randints

kk: kk.o
	$(CC) kk.o -o kk

%.o: %.cpp
	$(CC) $(CFLAGS) $<

clean:
	rm *.o kk randints