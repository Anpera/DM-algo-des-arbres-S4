CC = gcc
CFLAGS = -std=c17 -pedantic -Wall -g3

Filtrage : objets/filtrage.o objets/ABR.o
	$(CC) $(CFLAGS) -o $@ $^

Test : objets/ABR.o objets/test_ABR.o
	mkdir -p objets
	mkdir -p pdfs
	$(CC) $(CFLAGS) -o $@ $^

objets/filtrage.o : filtrage.c ABR.h
	mkdir -p objets
	mkdir -p pdfs
	$(CC) $(CFLAGS) -c -o $@ $<

objets/ABR.o : ABR.c ABR.h
	mkdir -p objets
	mkdir -p pdfs
	$(CC) $(CFLAGS) -c -o $@ $<

objets/test_ABR.o : test_ABR.c ABR.h
	$(CC)  $(CFLAGS) -c -o $@ $<

cleanDeluxe : cleanObj cleanPdf

cleanObj :
	rm -f objets/ABR.o
	rm -f objets/test_ABR.o
	rm -f objets/filtrage.o

cleanPdf :
	rm -f pdfs/*