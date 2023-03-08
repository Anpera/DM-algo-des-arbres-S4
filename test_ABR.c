#include "ABR.h"

int main(){
    Arbre A = NULL;
    char *mot = "coaplk^pafk^paihffopj";
    cree_arbre("test.txt", &A);
    suppression(&A, mot);
    parcours_infixe(A);
    dessine("pdfs/testis", A);

    libere(&A);

    return 0;
}