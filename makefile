CC=g++
CFLAGS=-std=gnu++0x
all: kk
kk: kk.o
	$(CC) $(CFLAGS) kk.o -o kk

%.o: %.cpp
	$(CC) $(CFLAGS) $<

clean:
	rm *.o kk