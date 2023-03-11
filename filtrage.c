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
	
	// char *extension = ".txt";
	// for (int i = 0; i < 4; i++){
	// 	if (fichier[len - 1 - i] != extension[3 - i])
	// 		return 1;
	// }
	// return 0;
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

int main(int argc, char *argv[]){
	char *file = "test.txt";
	char *file2 = "filtre.txt";
	int option = 0;

	if (argc != 3 && argc != 4)
		return 1;
	if (!strcmp(argv[1], "-v"))
	{
		option = 1;
		if (verif_fichier(argv[2]) == 1)
			return 1;
		file = argv[2];
		if (verif_fichier(argv[3]) == 1)
			return 1;
		file2 = argv[3];
	}
	else
	{
		if (verif_fichier(argv[1]) == 1)
			return 1;
		file = argv[1];
		if (verif_fichier(argv[2]) == 1)
			return 1;
		file2 = argv[2];
	}

    Arbre A = NULL;
    Arbre F = NULL;
    Arbre utilise = NULL;
	
    if (cree_arbre(file, &A) == 0)
		return 1;
    if (cree_arbre(file2, &F) == 0)
	{
	    libere(&A);
		return 1;
	}
	char *texte = name_pdf(file);
	char *filter = name_pdf(file2);
	if (option == 1){
		dessine(texte, A);
		dessine(filter, F);
		filtre(&A, &F, &utilise);
		parcours_infixe(A);
		dessine("pdfs/filtrage", A);
		dessine("pdfs/en_commun", utilise);
	}
	else{
		filtre(&A, &F, &utilise);
    	parcours_infixe(A);
	}
	free(texte);
	free(filter);
    libere(&A);
    libere(&F);
    libere(&utilise);
    return 0;
}