#!/usr/bin/make
CC = gcc
CFLAGS=-g -Imruby/include
LDFLAGS=-lmruby -lm -Lmruby/build/host/lib

all: smithy
smithy: smithy.c
		gcc $(CFLAGS) $? $(LDFLAGS) -o $@
clean:
		rm -f smithy *.o
