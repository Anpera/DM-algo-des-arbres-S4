#include "ABR.h"

/**
 * @brief Fonction allouant de la place mémoire pour un mot dans l'arbre
 * 
 * @param mot char *
 * @return Noeud* 
 */
Noeud * alloue_noeud(char * mot){
    Noeud * nouveau = (Noeud *) malloc(sizeof(Noeud));
    if (nouveau){
        nouveau->fg = NULL;
        nouveau->fd = NULL;
        // nouveau->mot = strdup(mot);  //Méthode 1
        nouveau->mot = (char *) calloc(strlen(mot) + 1, sizeof(char));//Alternative
        if (nouveau->mot){
            //strcpy(nouveau->mot, mot); //Alternative 1
            for (int i = 0; i < strlen(mot); i++) //Alternative2
                nouveau->mot[i] = mot[i];
        }
        else
            free(nouveau);
    }
    return nouveau; 
}

/**
 * @brief Fonction qui affichent un parcours infixe d'un arbre
 * 
 * @param A Arbre
 */
void parcours_infixe(Arbre A){
    if (A){
        parcours_infixe(A->fg);
        printf("%s\n", A->mot);
        parcours_infixe(A->fd);
    }
}

/**
 * @brief Fonction qui ajoute dans l'arbre un mot soit à gauche
 * soit à droite
 * 
 * @param A Arbre *
 * @param mot char *
 * @return Noeud* 
 */
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

/**
 * @brief Fonction qui enlève de l'arbre le plus grand mot
 * 
 * @param A Arbre *
 * @return Noeud* 
 */
Noeud * extrait_max(Arbre *A){
    Noeud * tmp;
    if (*A == NULL)
        return *A;
    if ((*A)->fd == NULL) {
        tmp = *A;
        *A = (*A)->fg;
        return tmp;
    }
    return extrait_max(&((*A)->fd));
}

/**
 * @brief Fonction qui supprime le mot donné en paramètre de l'arbre
 * s'il existe
 * 
 * @param A Arbre *
 * @param mot char *
 * @return Noeud* 
 */
Noeud * suppression(Arbre * A, char * mot){
	Noeud * tmp = NULL, * max = NULL;
	int cmp;
	if (*A == NULL)
		return *A;

	if (mot == NULL)
		return NULL;

	cmp = strcmp(mot, (*A)->mot);

	if (cmp < 0)
		return suppression(&((*A)->fg), mot);

	else if (cmp > 0)
		return suppression(&((*A)->fd), mot);
	
	else if (cmp == 0)
	{
		tmp = *A;
		if ((*A)->fg == NULL && (*A)->fd == NULL)
		{
			*A = NULL;
		}
		else if ((*A)->fg == NULL)
			*A = (*A)->fd;

		else if ((*A)->fd == NULL)
			*A = (*A)->fg;

		else {
			max = extrait_max(&((*A)->fg));
			max->fg = (*A)->fg;
			max->fd = (*A)->fd;
			(*A) = max;
		}
	}
	return tmp;
}

/**
 * @brief Fonction qui libère la place mémoire de l'arbre
 * 
 * @param A Arbre *
 */
void libere(Arbre * A){
    if (*A){
        libere(&(*A)->fg);
        libere(&(*A)->fd);
        free((*A)->mot);
        free(*A);
    }
}

/**
 * @brief Fonction qui écrit dans un fichier .dot le début du paramètrage
 * de celui-ci
 * 
 * @param f FILE *
 */
void ecrireDebut(FILE *f){
    fprintf(f, "digraph arbre {\n"
            "  node [shape = record, height = .1]\n"
            "  edge [tailclip = false , arrowtail = dot , dir = both ];\n\n");
}

/**
 * @brief Fonction écrivant l'arbre dans le fichier .dot
 * 
 * @param f FILE *
 * @param a Arbre
 */
void ecrireArbre(FILE *f, Arbre a){
    fprintf(f, "  n%p [label = \"<gauche> | <mot> %s | <droite>\"];\n", (void*)a, a->mot);
    if (a->fg){
        fprintf(f, "  n%p:gauche:c -> n%p:mot;\n", (void*)a, (void*)a->fg);
        ecrireArbre(f, a->fg);
    }

    if (a->fd){
        fprintf(f, "  n%p:droite:c -> n%p:mot;\n", (void*)a, (void*)a->fd);
        ecrireArbre(f, a->fd);
    }
}

/**
 * @brief Fonction qui écrit une "}" pour fermer le paramètrage du 
 * fichier .dot
 * 
 * @param f FILE *
 */
void ecrireFin(FILE *f){
    fprintf(f, "}\n");
}

/**
 * @brief Fonction qui dessine l'arbre du fichier .dot dans
 * un fichier .pdf
 * 
 * @param nom char *
 * @param A Arbre
 */
void dessine(char * nom, Arbre A){

    char *dotfile = (char *) malloc((sizeof(char)) * (strlen(nom) + 5));

    strcpy(dotfile, nom);
    strcat(dotfile, ".dot");

    FILE *fichier = fopen(dotfile, "w");
	if (fichier == NULL)
		return;

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

// Partie 2

/**
 * @brief Fonction qui récupère les mots d'un fichier .txt et les
 * insèrent un arbre
 * 
 * @param nom char *
 * @param A Arbre
 * @return int 
 */
int cree_arbre(char * nom, Arbre * A)
{
    FILE *fichier = fopen(nom, "r");
	if (fichier == NULL)
		return 0;
    char * buffer = (char *) calloc(512, sizeof(char));
    const char * separateurs = " \n,;:.?!\"()-'";

    char * strToken;

    while (! feof(fichier)){
        fgets( buffer, 512, fichier);

        if (ferror(fichier)){
            fprintf(stderr, "Erreur\n");
            libere(A);
            break;
        }

        strToken = strtok(buffer, separateurs);

        while (strToken){
            ajout(A, strToken);
            strToken = strtok(NULL, separateurs);
        }

    }
    free(buffer);
    fclose(fichier);

    return 1;
}
