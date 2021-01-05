#include "header.h"

void	initJeu(Cand C[9][9], int *NBO, Case *O, int **G)
{
	int i;
	int j;
	int k;

	(*NBO) = 0;
	for (i = 0; i < 9; i++)   // Parcours des lignes
		for (j = 0; j < 9; j++)   // Parcours des colonnes
		{
			C[i][j].nbc = 0;   // Initialisation du nombre de candidat
			if (G[i][j] == 0)   // Si la case est ouverte
			{
				C[i][j].tab = (int*)malloc(sizeof(int) * 9);   // On donne une taille physique de 9 (max de 9 candidats) à tab
				for (k = 1; k <= 9; k++)   // On test tout les chiffres de 1 à 9
					if (estCand(G, i, j, k) == TRUE)   // On vérifie s'il est candidat
					{
						C[i][j].tab[C[i][j].nbc] = k;   // Si'il l'est, on le rajoute à la liste des candidats
						C[i][j].nbc += 1;   // On incrémente le nombre e candidats
					}
                      /* Enregistrement des coordonnées dans O*/
				O[*NBO].x = i;
				O[*NBO].y = j;
				(*NBO) += 1;
			}
			else
				C[i][j].tab = NULL;   // Si la case est fermée, on met tab à NULL
		}
}
