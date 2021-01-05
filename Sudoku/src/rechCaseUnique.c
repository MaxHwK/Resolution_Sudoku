#include "header.h"

int		*rechCaseUnique(Cand C[9][9], Case *O, int NBO)
{
	int c;   // index dans O
	int d;
	int line;
	int col;
	int *Res;   // Res[0] = indice dans O, Res[1] = valeur du candidat unique

	Res = (int*)malloc(sizeof(int) * 2);
	for (c = 0; c < NBO; c++)   // Parcours des cases ouvertes
	{
		line = O[c].x;
		col = O[c].y;
		for (d = 0; d < C[line][col].nbc; d++)   // Parcours des candidats d'une case
			if (estCandUnique(C, line, col, C[line][col].tab[d]))   // Si le candidat est unique
			{
				Res[0] = c;   // On enregistre l'indice dans O
				Res[1] = C[line][col].tab[d];   // On enregistre la valeur du candidat
				return (Res);   // On retourne l'indice et la valeur
			}
	}
	return (NULL);   // Si on ne trouve pas de case unique, on renvoie NULL
}
