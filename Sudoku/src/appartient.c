#include "header.h"

int		appartient(Cand C[9][9], int x, int y, int nb)
{
	int c;

	for (c = 0; c < C[x][y].nbc; c++)   // Parcours des candidats de la case donnée
		if (C[x][y].tab[c] == nb)
			return (c);   // S'il est trouvé
	return (-1);   // S'il n'est pas trouvé
}
