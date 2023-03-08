CC = gcc
CFLAGS = -std=c17 -pedantic -Wall

Test : objets/ABR.o objets/test_ABR.o
	mkdir -p objets
	mkdir -p pdfs
	$(CC) -o $@ $^

objets/ABR.o: ABR.c ABR.h
	mkdir -p objets
	mkdir -p pdfs
	$(CC) -c -o $@ $<

objets/test_ABR.o : test_ABR.c ABR.h
	$(CC) -c -o $@ $<

cleanDeluxe: cleanObj cleanPdf

cleanObj:
	rm -f objets/ABR.o
	rm -f objets/test_ABR.o

cleanPdf:
	rm -f pdfs/*