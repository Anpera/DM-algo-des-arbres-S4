#include "ABR.h"

int main(){
    Arbre A = NULL;
    char *mot = "de";
    cree_arbre("test.txt", &A);
    dessine("pdfs/testis", A);
    Noeud * supp = suppression(&A, mot);

    free(supp->mot);
    free(supp);
    dessine("pdfs/testis2", A);

    libere(&A);

    return 0;
}