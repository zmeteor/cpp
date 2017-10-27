src = $(wildcard *.c)
targets = $(patsubst %.c, %, $(src))

CC = gcc
CFLAGS = -Wall -g -L /usr/lib/mysql/lib/ -I /usr/include/mysql/include -lmysqlclient

all:$(targets)

$(targets):%:%.c
	$(CC) $< -o $@ $(CFLAGS)

.PHONY:clean all
clean:
	-rm -rf $(targets) 

