#include "header.h"

int		main(void)
{
	int **G;
	char str1[BUF_SIZE];
	char *str2;
	Cand C[9][9];
	int NBO;
	Case O[81];
                      /* Saisie du nom du fichier */
	printf("Saisissez le nom du fichier contenant la grille :\n");
	fgets(str1, BUF_SIZE, stdin);
	str2 = NULL;
	str2 = ft_strcpy(str1, str2);   // On prend juste le nom du fichier
	if ((G = lireGrille(str2)) != NULL)   // Si on a pu lire la grille
	{
		ecrireGrille(G);   // On affiche la grille
		initJeu(C, &NBO, O, G);   // On initialise les tables
		ecrireCand(C, NBO);   // On affiche les candidats
		fermerGrille(C, O, NBO, G);   // On lance le solver
	}
}
