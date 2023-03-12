CC = gcc
CFLAGS = -std=c17 -pedantic -Wall -g3

Filtrage : objets/filtrage.o objets/ABR.o
	$(CC) $(CFLAGS) -o $@ $^

Test : objets/ABR.o objets/test_ABR.o
	mkdir -p objets
	mkdir -p pdfs
	$(CC) $(CFLAGS) -o $@ $^

objets/filtrage.o : src/filtrage.c src/ABR.h
	mkdir -p objets
	mkdir -p pdfs
	$(CC) $(CFLAGS) -c -o $@ $<

objets/ABR.o : src/ABR.c src/ABR.h
	mkdir -p objets
	mkdir -p pdfs
	$(CC) $(CFLAGS) -c -o $@ $<

objets/test_ABR.o : src/test_ABR.c src/ABR.h
	$(CC)  $(CFLAGS) -c -o $@ $<

cleanDeluxe : cleanObj cleanPdf

cleanObj :
	rm -f objets/*

cleanPdf :
	rm -f pdfs/*