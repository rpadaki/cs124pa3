CC=g++

all: kk
kk: kk.o
	$(CC) kk.o -o kk

%.o: %.cpp
	$(CC) $<

clean:
	rm *.o kk