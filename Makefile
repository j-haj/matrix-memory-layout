CC := gcc
CFLAGS := -Wall -pedantic
SRC := src

all: memory_layout.o main.o
	$(CC) $(CFLAGS) -o run_mapper main.o memory_layout.o

main.o: $(SRC)/main.c
	$(CC) $(CFLAGS) -c $(SRC)/main.c

memory_layout.o: $(SRC)/memory_layout.c $(SRC)/memory_layout.h
	$(CC) $(CFLAGS) -c $(SRC)/memory_layout.h $(SRC)/memory_layout.c

.PHONY: clean
clean:
	rm *.o
	rm *.gch
	rm run_mapper
