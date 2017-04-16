CC=g++
CFLAGS=-std=gnu++0x -c -Wall

all: repstd kkalg kk

repstd: repstd.o kkimp.o rep.o
	@ld -r repstd.o kkimp.o rep.o -o repfull.o

repprep: repprep.o kkimp.o rep.o
	@ld -r repprep.o kkimp.o rep.o -o repfull.o

%alg: %alg.o
	@ld -r $< repfull.o -o kkdep.o

randints: randints.o
	@$(CC) randints.o -o randints

kk: kk.o
	@$(CC) kk.o kkdep.o -o kk

%.o: %.cpp
	@$(CC) $(CFLAGS) $<

clean:
	-@rm -rf *.o kk randints>/dev/null || true