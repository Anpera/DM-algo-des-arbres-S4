#include "ABR.h"

int main(){
    char strings[30];
    strcpy(strings, "bonjour");
    Arbre a = alloue_noeud(strings);
    strcpy(strings, "bye");
    ajout(&a, strings);
    strcpy(strings, "hello");
    ajout(&a, strings);
    strcpy(strings, "aled");
    ajout(&a, strings);
    strcpy(strings, "a");
    ajout(&a, strings);
    strcpy(strings, "fini !");
    ajout(&a, strings);
    strcpy(strings, "coucou");
    ajout(&a, strings);
    strcpy(strings, "bonjour");
    ajout(&a, strings);

    parcours_infixe(a);

    strcpy(strings, "pdfs/testis");

    dessine(strings, a);

    libere(&a);

    return 0;
}