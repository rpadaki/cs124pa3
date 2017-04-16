CC=g++
CFLAGS=-std=gnu++0x
all: kk
kk: kk.o
	$(CC) kk.o -o kk

%.o: %.cpp
	$(CC) $<

clean:
	rm *.o kk