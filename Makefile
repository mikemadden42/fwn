src = $(wildcard *.c)
obj = $(src:.c=.o)

BINARY=fwn
CC=gcc
#CC=clang
CFLAGS=-Wall -Wextra -O3 -std=c11 -pedantic -march=native
LDFLAGS=

all: $(BINARY)

$(BINARY): $(obj)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
	strip $@

.PHONY: clean
clean:
	rm -f $(obj) $(BINARY)
