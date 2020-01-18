## Makefile for Bloom Filter test
## nmt 2018

CC = g++

all:	dij.o graph.o dij_test

dij.o: dij.cpp
	$(CC) $(CFLAGS) -c dij.cpp

graph.o: graph.cpp
	$(CC) $(CFLAGS) -c graph.cpp

dij_test: dij.o dij.h dij_cfg.h graph.o graph.h graph_cfg.h
	$(CC) $(CFLAGS) -o dij_test dij.o graph.o main.cpp

clean:
	rm *.o dij_test
