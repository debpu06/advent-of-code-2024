CC = gcc
CFLAGS = -std=c2x -Wall -Wextra -Iutility -Werror -Wpedantic
SRCS = main.c dayone.c utility/sort.c
OBJS = $(SRCS:.c=.o)
TARGETS = main dayone

.PHONY: all clean

all: $(TARGETS)

main: main.o utility/sort.o
	$(CC) $(CFLAGS) -o $@ $^

dayone: dayone.o utility/sort.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGETS)