CC=g++
CFLAGS=-std=gnu++0x -c -Wall

all: repstd kkalg kk

repstd: repstd.o kkimp.o rep.o
	@ld -r repstd.o kkimp.o rep.o -o repfull.o>/dev/null || true

repprep: repprep.o kkimp.o rep.o
	@ld -r repprep.o kkimp.o rep.o -o repfull.o>/dev/null || true

%alg: %alg.o
	@ld -r $< repfull.o -o kkdep.o>/dev/null || true

randints: randints.o
	@$(CC) randints.o -o randints>/dev/null || true

kk: kk.o
	@$(CC) kk.o kkdep.o -o kk>/dev/null || true

%.o: %.cpp
	@$(CC) $(CFLAGS) $<>/dev/null || true

clean:
	-@rm -rf *.o kk randints>/dev/null || true