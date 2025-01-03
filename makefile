PROGS = a
CC = g++
all: a
.cpp:
	$(CC) -I . $<
