#include "ABR.h"

int filtre(Arbre *A, Arbre *F, Arbre *utilises){
	Noeud *supp = suppression(A, (*F)->mot);
	if (supp){
		ajout(utilises, supp->mot);
		free(supp->mot);
		free(supp);
	}
	if ((*F)->fg)
		filtre(A, &(*F)->fg, utilises);
	if ((*F)->fd)
		filtre(A, &(*F)->fd, utilises);
	return 0;
}

int	verif_fichier(char *fichier){
	int len = strlen(fichier);
	if (len < 5)
		return 1;
	return !!strcmp(&fichier[len - 4], ".txt");
}

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

void affichage(Arbre A, Arbre commun){
	printf("Mots présents uniquement dans le texte de référence :\n");
	printf("-----------------------------------------------------\n\n");
	parcours_infixe(A);
	printf("\nMots présents dans les deux textes :\n");
	printf("------------------------------------\n\n");
	parcours_infixe(commun);
}

void liberation(char * texte, char * filter, Arbre A, Arbre F, Arbre utilise){
	free(texte);
	free(filter);
	libere(A);
	libere(F);
	libere(utilise);
}

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
	filtre(&A, &F, &utilise);
	
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
		return 1;
	}

	for (int i = 1; i<argc; i++){
		if (strcmp(argv[i], "-v") == 0){
			if (argc != 4)
				return 1;
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
	
	lancement(option, fichier, filtre);

	return 0;
}