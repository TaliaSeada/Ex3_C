CC=gcc
FLAGS= -Wall -g

#make all
all: stringProg

.PHONY: clean
#make clean
clean: 
	rm -f *.o *.a *.so stringProg

stringProg: main.o
	$(CC) $(FLAGS) -o stringProg main.c

main.o: main.c 
	$(CC) $(FLAGS) -c main.c
