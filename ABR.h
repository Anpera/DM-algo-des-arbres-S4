#ifndef __ABR_H_
#define __ABR_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct noeud{
    char * mot;
    struct noeud *fg, *fd;
} Noeud, *Arbre;

Noeud * alloue_noeud(char * mot);
void parcours_infixe(Arbre A);
void minuscule(char * mot);
Noeud * ajout(Arbre *A, char *mot);
void libere(Arbre * A);
void ecrireDebut(FILE *f);
void ecrireArbre(FILE *f, Arbre a);
void ecrireFin(FILE *f);
void dessine(char * nom, Arbre A);

#endif