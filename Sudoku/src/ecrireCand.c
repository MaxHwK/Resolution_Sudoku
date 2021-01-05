#include "header.h"

int		candmax(Cand C[9][9])
{
	int max;
	int i;
	int j;

	max = 0;
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
			if (C[i][j].nbc > max)
				max = C[i][j].nbc;   // Recherche du maximum
	return (max);
}

void	ecrireCand(Cand C[9][9], int NBO)
{
	int i;
	int j;
	int k;
	int l;
	int max;

	printf("\nVoici les candidats des %i cases ouvertes de la grille :\n", NBO);
	max = candmax(C);     // On cherche le nombre maximum de candidats pour déterminer le nombre de caractères à afficher par case
	for (i = 0; i < 9; i++)
	{
		printf("*");   // Affichage de l'étoile de début de ligne
		if (i % 3 == 0)
			for (k = 0; k < (27 + (9 * max)); k++)   // Affichage de la ligne d'étoile une ligne sur trois
				printf("*");
		else
		{
			for (l = 0; l < 3; l++)
			{
				for (k = 0; k < (8 + (3 * max)); k++)   // Sinon, affichage de la ligne de trait
					printf("-");
				printf("*");   // Affichage de la séparation verticale des blocs
			}
		}
		printf("\n*");
		for (j = 0; j < 9; j++)
		{
			printf(" ");
			for (k = 0; k < (max - C[i][j].nbc); k++)   // Affichage des espaces nécessaire pour aligner les chiffres à droite
				printf(" ");
			for (k = 0; k < C[i][j].nbc; k++)
				printf("%i", C[i][j].tab[k]);   // Affichage des candidats
			if (j % 3 == 2)
				printf(" *");   // Affichage du séparateur de bloc
			else
				printf(" |");   // Sinon affichage du séparateur de case
		}
		printf("\n");
	}
	for (k = 0; k < (28 + (9 * max)); k++)   // Affichge de la ligne d'étoile en bas
		printf("*");
	printf("\n");
}
