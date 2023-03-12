#include "ABR.h"

/**
 * @brief 	Filtre l'arbre A en utilisant l'arbre F et place
 * 		 	le noeud filtré dans l'arbre utilises 
 * 
 * @param A 		Arbre du texte
 * @param F 		Arbre du filtre
 * @param utilises 	Arbre des mots filtrés
 */
void filtre(Arbre *A, Arbre F, Arbre *utilises){
	Noeud *supp = suppression(A, F->mot);
	if (supp){
		ajout(utilises, supp->mot);
		free(supp->mot);
		free(supp);
	}
	if (F->fg)
		filtre(A, F->fg, utilises);
	if (F->fd)
		filtre(A, F->fd, utilises);
}

/**
 * @brief 	Vérifie si le chemin de fichier donné est 
 * 			bien un fichier .txt
 * 
 * @param fichier 	Chemin du fichier
 * @return int 		Booléen pour savoir si c'est le cas
 */
int	verif_fichier(char *fichier){
	int len = strlen(fichier);
	if (len < 5)
		return 1;
	return !!strcmp(&fichier[len - 4], ".txt");
}

/**
 * @brief 	Créer une chaîne de caractère à partir du nom
 * 			de fichier pour retourner un chemin d'accès
 * 			à partir d'un dossier pdfs/
 * 
 * @param file 		Nom du fichier
 * @return char* 	Chaîne de caractère
 */
char* name_pdf(char * file){
	char *ptr = malloc((strlen(file) +2) * sizeof(char));
	char nom_pdf[strlen(file) - 3];
	for (int i = 0; i < strlen(file) - 4; i++)
	{
		nom_pdf[i] = file[i];
	}
	nom_pdf[strlen(file) - 4] = '\0';
	strcpy(ptr, "pdfs/");
	strcat(ptr , nom_pdf);
	return ptr;
}

/**
 * @brief 	Affiche les mots contenu dans l'arbre A et
 * 			l'arbre commun
 * 
 * @param A 		Arbre du fichier de texte filtré
 * @param commun 	Arbre des mots en communs entre A et le filtre
 */
void affichage(Arbre A, Arbre commun){
	printf("Mots présents uniquement dans le texte de référence :\n");
	printf("-----------------------------------------------------\n\n");
	parcours_infixe(A);
	printf("\nMots présents dans les deux textes :\n");
	printf("------------------------------------\n\n");
	parcours_infixe(commun);
}

/**
 * @brief	Libère toutes les allocations faites.
 * 
 * @param texte  	Accès vers fichier pdf du fichier de texte
 * @param filter 	Accès vers fichier pdf du fichier de filtre
 * @param A 		Arbre du texte
 * @param F 		Arbre du filtre
 * @param utilise 	Arbre des mots filtrés
 */
void liberation(char * texte, char * filter, Arbre * A, Arbre * F, Arbre * utilise){
	free(texte);
	free(filter);
	libere(A);
	libere(F);
	libere(utilise);
}

/**
 * @brief 	Lance le filtrage de l'arbre, affiche et dessine le résultat
 * 
 * @param option 	Option si la création des pdfs est activée
 * @param fichier 	nom du fichier du texte
 * @param filtreur 	nom du fichier du filtre
 * @return int 		Indicateur si l'allocation de mémoire s'est bien passé
 */
int lancement(int option, char* fichier, char* filtreur){
	Arbre A = NULL;
	Arbre F = NULL;
	Arbre utilise = NULL;
	char *texte = name_pdf(fichier);
	char *filter = name_pdf(filtreur);

	if (cree_arbre(fichier, &A) == 0 || cree_arbre(filtreur, &F) == 0){
		free(texte);
		free(filter);
		return 0;
	}

	if (option){
		dessine(texte, A);
		dessine(filter, F);
	}
	filtre(&A, F, &utilise);
	
	affichage(A, utilise);

	if (option){
		dessine("pdfs/filtrage", A);
		dessine("pdfs/en_commun", utilise);
	}

	liberation(texte, filter, &A, &F, &utilise);

	return 1;
}


int main(int argc, char *argv[]){
	int option = 0;
	int levier = 0;
	char* fichier = NULL;
	char* filtre = NULL;

	if (argc < 3 || argc > 4){
		printf("Erreur : Des arguments en trop ou un manque d'arguments ont été trouvés.\n");
		return 1;
	}

	for (int i = 1; i<argc; i++){
		if (strcmp(argv[i], "-v") == 0){
			if (argc != 4){
				printf("Erreur : argument insuffisant malgré l'option activée.\n");
				return 1;
			}
			else
				option = 1;
		}

		else{
			if (verif_fichier(argv[i]) == 0){
				if (!levier){
					fichier = argv[i];
					levier = 1;
				}
				else{
					filtre = argv[i];
				}
					
			}
		}
	}
	
	if (!lancement(option, fichier, filtre))
		printf("Il y a eu une erreur lors de l'allocation de mémoire.\n");

	return 0;
}
