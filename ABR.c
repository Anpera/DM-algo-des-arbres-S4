#include "ABR.H"

Noeud * alloue_noeud(char * mot){
    Noeud * nouveau = (Noeud *) malloc(sizeof(Noeud));
    if (nouveau){
        nouveau->fg = NULL;
        nouveau->fd = NULL;
        //nouveau->mot = strdup(mot);  //Méthode 1
        nouveau->mot = (char *) malloc(sizeof(mot)); //Alternative
        // //strcpy(nouveau->mot, mot); //Alternative 1
        for (int i = 0; i <= strlen(mot); ++i){ //Alternative 2
            nouveau->mot[i] = mot[i];
        }
    }
    return nouveau;
}

void parcours_infixe(Arbre A){
    if (A){
        parcours_infixe(A->fg);
        printf("%s\n", A->mot);
        parcours_infixe(A->fd);
    }
}

void libere(Arbre * A){
    if (*A){
        libere(&(*A)->fg);
        libere(&(*A)->fd);
        free(*A);
    }
}

int main(){
    char mot[] = "Bonjour";
    Arbre a = alloue_noeud(mot);
    a->fg = alloue_noeud("Au revoir");
    a->fd = alloue_noeud("Bisous");
    parcours_infixe(a);
    libere(&a);

    return 0;
}