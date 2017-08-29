CC := gcc
CFLAGS := -Wall -pedantic

all:
	$(CC) $(CFLAGS) -o run_mapper main.c

.PHONY: clean
clean:
	rm run_mapper
