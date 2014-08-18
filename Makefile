#!/usr/bin/make
CC = gcc
CFLAGS=-g -Imruby/include
LDFLAGS=-lmruby -lm -Lmruby/build/host/lib

all: mruby/build/host/lib/libmruby.a smithy
smithy: smithy.c
	$(CC) $(CFLAGS) $? $(LDFLAGS) -o $@
mruby/build/host/lib/libmruby.a:
	cd mruby; rake
clean:
	rm -rf smithy *.o *.dSYM
