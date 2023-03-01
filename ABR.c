#include "ABR.H"

Noeud * alloue_noeud(char * mot){
    Noeud * nouveau = (Noeud *) malloc(sizeof(Noeud));
    if (nouveau){
        nouveau->fg = NULL;
        nouveau->fd = NULL;
        //nouveau->mot = strdup(mot);  //Méthode 1
        nouveau->mot = (char *) malloc(sizeof(char) * strlen(mot)); //Alternative
        //strcpy(nouveau->mot, mot); //Alternative 1
        for (int i = 0; i < strlen(mot); ++i){ //Alternative 2
        // OU mot[i] != '\0' OU mot[i]
            nouveau->mot[i] = mot[i];
        }
    }
    return nouveau;
}

void libere(Arbre * A){
    if (*A){
        libere(&(*A)->fg);
        libere(&(*A)->fd);
        free(*A);
    }
}

int main(){
    Arbre a = alloue_noeud("Bonjour fdshfdsjhfdsjhgdsjhg");
    printf("%s\n", a->mot);
    libere(&a);

    return 0;
}