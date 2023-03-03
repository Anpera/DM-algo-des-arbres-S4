#include "ABR.H"

Noeud * alloue_noeud(char * mot){
    Noeud * nouveau = (Noeud *) malloc(sizeof(Noeud));
    if (nouveau){
        nouveau->fg = NULL;
        nouveau->fd = NULL;
        // nouveau->mot = strdup(mot);  //Méthode 1
        nouveau->mot = (char *) malloc(sizeof(mot));//Alternative
        if (nouveau->mot){
            //strcpy(nouveau->mot, mot); //Alternative 1
            for (int i = 0; i <strlen(mot); i++) //Alternative2
                nouveau->mot[i] = mot[i];
        }
        else
            free(nouveau);
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

void minuscule(char * mot){
    for (int i = 0; mot[i] != '\0'; i++){
        if (mot[i] < 'a')
            mot[i] = mot[i] + 'a' - 'A'; 
    }
}

Noeud * ajout(Arbre *A, char *mot){
    if (*A){
        int cmp = strcmp(mot, (*A)->mot);
        
        if (cmp < 0)
            ajout(&(*A)->fg, mot);

        else if (cmp > 0)
            ajout(&(*A)->fd, mot);

        else
            return NULL;
    }
    else{
        *A = alloue_noeud(mot);
        return *A;
    }
}

void libere(Arbre * A){
    if (*A){
        libere(&(*A)->fg);
        libere(&(*A)->fd);
        free((*A)->mot);
        free(*A);
    }
}

int main(){
    Arbre a = alloue_noeud("bonjour");
    ajout(&a, "bye");
    ajout(&a, "hello");
    ajout(&a, "aled");
    ajout(&a, "a");
    ajout(&a, "fini !");
    ajout(&a, "coucou");
    ajout(&a, "bonjour");

    parcours_infixe(a);

    libere(&a);

    return 0;
}