#include "header.h"

bool	ft_shake_block(int **G, int x, int y, int nb)
{
	int i;
	int j;
                      /* Parcours du bloc */
	for (i = (x / 3) * 3; i < (x / 3) * 3 + 3; i++)   // Même modèle que estCandUnique
		for (j = (y / 3) * 3; j < (y / 3) * 3 + 3; j++)
			if (nb == G[i][j])
				return (FALSE);   // Si on trouve nb dans la grille
	return (TRUE);   // Si on ne trouve pas nb dans la grille
}

bool	ft_shake_col(int **G, int y, int nb)
{
	int i;
                      /* Parcours de la colonne */
	for (i = 0; i < 9; i++)
		if (nb == G[i][y])
			return (FALSE);   // Si on trouve nb dans la grille
	return (TRUE);   // Si on ne trouve pas nb dans la grille
}

bool	ft_shake_line(int **G, int x, int nb)
{
	int j;
                      /* Parcours de la ligne */
	for (j = 0; j < 9; j++)
		if (nb == G[x][j])
			return (FALSE);   // Si on trouve nb dans la grille
	return (TRUE);   // Si on ne trouve pas nb dans la grille
}

bool	estCand(int **G, int x, int y, int nb)
{
	if (ft_shake_block(G, x, y, nb) == TRUE)   // Si le nombre n'apparaît pas dans le bloc
		if (ft_shake_col(G, y, nb) == TRUE)   // Si le nombre n'apparaît pas dans la colonne
			if (ft_shake_line(G, x, nb) == TRUE)   // Si le nombre n'apparaît pas dans la ligne
				return (TRUE);   // Si le nombre est candidat
	return (FALSE);   // Si le nombre n'est pas candidat
}
