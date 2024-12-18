CFLAGS=-Wall -Wextra -pedantic -std=c11 -ggdb

heap: main.c
	$(CC) $(CFLAGS) -o heap main.c