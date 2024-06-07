CC = gcc
CFLAGS = -O2 -Wall -Wextra
LDLIBS =
SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)
BINS := $(SRCS:%.c=bin/%)

.PHONY: all

all: clean prep $(BINS)

$(BIN): $(OBJS)
	$(CC) -c $(CFLAGS) -o $(OBJS)

bin/% : %.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

prep: 
	mkdir -p bin

clean: 
	rm -f ./bin/* > /dev/null || true

