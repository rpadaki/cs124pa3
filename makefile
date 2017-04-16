CC=g++
CFLAGS=-std=gnu++0x -c -Wall

all: kk

kk: kk.o
	$(CC) kk.o -o kk

%.o: %.cpp
	$(CC) $(CFLAGS) $<

clean:
	rm *.o kk