# Makefile

CC=g++
IDIR=-I.
CFLAGS=$(IDIR) -DUSING_MALLOC -g -W -Wall -Wno-unused-parameter -Wno-deprecated

C_FILES=$(wildcard *.c)
O_FILES=$(C_FILES:.c=.o)

.PHONY: clean

all: $(O_FILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(O_FILES)
