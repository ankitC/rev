all: sort

sort: sort.o
		 gcc -o sort sort.o

sort.o: sort.c
		 gcc -c  sort.c

clean:
		 rm sort.o sort
