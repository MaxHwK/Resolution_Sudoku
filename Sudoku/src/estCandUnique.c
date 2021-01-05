#include "header.h"

bool	est_Seul_Bloc(Cand C[9][9], int x, int y, int nb)
{
	int i;
	int j;
                      /* Parcours du bloc */
	for (i = (x / 3) * 3; i < (x / 3) * 3 + 3; i++)   // i = (x / 3) * 3 pour avoir la ligne du haut du bloc, et même chose plus 3 pour parcourir les 3 lignes du bloc
		for(j = (y / 3) * 3; j < (y / 3) * 3 + 3; j++)   // j = (y / 3) * 3 pour avoir la colonne de droite du bloc, et même chose plus 3 pour parcourir les 3 colonnes du bloc
			if(i != x || j != y)   // On vérifie qu'on n'est pas sur la case de départ
				if (appartient(C, x, y, nb) != -1)   // On vérifie s'il est dans la liste des candidats
					return(FALSE);   // Si on trouve nb
	return(TRUE);   // Si on ne trouve pas nb
}

bool	est_Seul_Col(Cand C[9][9], int x, int y, int nb)
{
	int i;
                      /* Parcours de la colonne */
	for (i = 0; i < 9; i++)
		if (i != x)   // On vérifie qu'on n'est pas sur la case de départ
			if (appartient(C, i, y, nb) != -1)   // On vérifie s'il est dans la liste des candidats
				return (FALSE);   // Si on trouve nb
	return (TRUE);   // Si on ne trouve pas nb
}

bool	est_Seul_Ligne(Cand C[9][9], int x, int y, int nb)
{
	int j;
                      /* Parcours de la ligne */
	for (j = 0; j < 9; j++)
		if (j != y)   // On verifie qu'on n'est pas dans la case de départ
			if (appartient(C, x, j, nb) != -1)   // On vérifie s'il est dans la liste des candidats
				return (FALSE);   // Si on trouve nb
	return (TRUE);   // Si on ne trouve pas nb
}

bool	est_Seul_Dans_Case(Cand C[9][9], int x, int y)
{
	return (C[x][y].nbc == 1);   // S'il n'y a qu'un candidat, nb est le seul candidat de la case
}

bool	estCandUnique(Cand C[9][9], int x, int y, int nb)
{
                      /* Vérification des conditions pour être candidat unique */
	return (est_Seul_Dans_Case(C, x, y) || est_Seul_Ligne(C, x, y, nb) || est_Seul_Col(C, x, y, nb) || est_Seul_Bloc(C, x, y, nb));
}
