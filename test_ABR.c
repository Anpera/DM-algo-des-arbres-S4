#include "ABR.h"

int main(){
    Arbre A = NULL;

    cree_arbre("test.txt", &A);

    parcours_infixe(A);

    dessine("pdfs/testis", A);

    libere(&A);

    return 0;
}