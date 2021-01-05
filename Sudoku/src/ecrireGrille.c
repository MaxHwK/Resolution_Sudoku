#include <stdio.h>
#include <stdlib.h>

void	ecrireGrille(int **G)
{
	int i;
	int j;

	printf("\nAffichage de la grille :\n");
	for (i = 0; i < 9; i++)
	{
		if (i % 3 == 0)
			printf("-------------\n");   // Affichage de la ligne de haut du bloc
		for (j = 0; j < 9; j++)
		{
			if (j % 3 == 0)
				printf("|");   // Affichage de la séparation verticale des blocs
			printf("%i", G[i][j]);   // Affichage de la valeur de la case
		}
		printf("|\n");
	}
	printf("-------------\n");   // Affichage de la ligne du bas
}
