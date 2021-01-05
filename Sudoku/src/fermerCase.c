#include "header.h"

void	supressTable(Cand C[9][9], int x, int y, int c)
{
	int d;
                      /* On supprime la valeur de la table */
	for (d = c; d < C[x][y].nbc; d++)
		C[x][y].tab[d] = C[x][y].tab[d  + 1];
	C[x][y].nbc -= 1;   // On réduit donc la taille de la tale de 1
}

void	fermer_bloc(Cand C[9][9], int x, int y, int nb)
{
	int i;
	int j;
	int c;
                      /* Parcours du bloc */
	for (i = (x / 3) * 3; i < ((x / 3) * 3) + 3; i++)       // On parcours comme dans estCandUnique pour parcourir le bloc
		for (j = (y / 3) * 3; j < ((y / 3) * 3) + 3; j++)
			if ((c = appartient(C, i, j, nb)) != -1)   // Si le nombre appartient à la liste des candidats
				supressTable(C, i, j, c);   // On le supprime
}

void	fermer_col(Cand C[9][9], int y, int nb)
{
	int i;
	int c;
                      /* Parcours de la colonne */
	for (i = 0; i < 9; i++)
		if ((c = appartient(C, i, y, nb)) != -1)   // Si le nombre appartient à la liste des candidats
			supressTable(C, i, y, c);   // On le supprime
}

void	fermer_line(Cand C[9][9], int x, int nb)
{
	int j;
	int c;
                      /* Parcours de la ligne */
	for (j = 0; j < 9; j++)
		if ((c = appartient(C, x, j, nb)) != -1)   // Si le nombre appartient à la liste des candidats
			supressTable(C, x, j, c);   // On le supprime
}

void	fermerCase(Cand C[9][9], Case *O, int *NBO, int c, int **G, int nb)
{
	int x;
	int y;
	int d;

	x = O[c].x;
	y = O[c].y;
	printf("\nFermeture de la case (%i,%i) avec le nombre %i\n", x, y, nb);
                      /* Supression des candidats */
	fermer_line(C, x, nb);   // Suppression des candidats de la ligne
	fermer_col(C, y, nb);   // Suppression des candidats de la colonne
	fermer_bloc(C, x, y, nb);   // Suppression des candidats du bloc

	G[x][y] = nb;   // Remplissage de la grille
                      /* Réinitialisation des candidats de la case */
	C[x][y].nbc = 0;
	C[x][y].tab = NULL;
                      /* Supression de la case dans O */
	for (d = c; d < (*NBO - 1); d++)
		O[d] = O[d + 1];
	*NBO = *NBO - 1;
}
