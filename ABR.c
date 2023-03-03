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
    return NULL;
}

void libere(Arbre * A){
    if (*A){
        libere(&(*A)->fg);
        libere(&(*A)->fd);
        free((*A)->mot);
        free(*A);
    }
}

void ecrireDebut(FILE *f){
    fprintf(f, "digraph arbre {\n"
            "  node [shape = record, height = .1]\n"
            "  edge [tailclip = false , arrowtail = dot , dir = both ];\n\n");
}

void ecrireArbre(FILE *f, Arbre a){
    fprintf(f, "  n%p [label = \"<gauche> | <mot> %s | <droit>\"];\n", a, a->mot);
    if (a->fg){
        fprintf(f, "  n%p:gauche:c -> n%p:mot;\n", a, a->fg);
        ecrireArbre(f, a->fg);
    }

    if (a->fd){
        fprintf(f, "  n%p:droit:c -> n%p:mot;\n", a, a->fd);
        ecrireArbre(f, a->fd);
    }
}

void ecrireFin(FILE *f){
    fprintf(f, "}\n");
}

void dessine(char * nom, Arbre A){

    char *dotfile = (char *) malloc((sizeof(char)) * (strlen(nom) + 4));

    strcpy(dotfile, nom);
    strcat(dotfile, ".dot");

    FILE *fichier = fopen(dotfile, "w");

    ecrireDebut(fichier);
    ecrireArbre(fichier, A);
    ecrireFin(fichier);
    fclose(fichier);

    int len = strlen(nom)*2 + 25;
    char cmd[len];
    strcpy(cmd, "dot -Tpdf ");
    strcat(cmd, dotfile);
    strcat(cmd, " -o ");
    strcat(cmd, nom);
    strcat(cmd, ".pdf");
    system(cmd);

    free(dotfile);
}