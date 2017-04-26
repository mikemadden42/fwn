src = $(wildcard *.c)
obj = $(src:.c=.o)

BINARY=fwn
CC=cc
CFLAGS=-Wall -Wextra -O3 -std=c11 -pedantic -march=native
#CFLAGS=-Wall -Wextra -O3 -std=c11 -pedantic -march=native -fsanitize=address
#CFLAGS=-Wall -Wextra -O3 -std=c11 -pedantic -march=native -fsanitize=memory
#CFLAGS=-Wall -Wextra -O3 -std=c11 -pedantic -march=native -fsanitize=thread
#CFLAGS=-Wall -Wextra -O3 -std=c11 -pedantic -march=native -fsanitize=undefined
LDFLAGS=

all: $(BINARY)

$(BINARY): $(obj)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
	strip $@

.PHONY: clean
clean:
	rm -f $(obj) $(BINARY)
