#include "header.h"

void	fermerGrille(Cand C[9][9], Case *O, int NBO, int **G)
{
	int *c;   // c[0] = index dans O, c[1] = valeur avec laquelle on ferme la case

	while ((c = rechCaseUnique(C, O, NBO)) != NULL)   // Tant qu'on trouve une case remplissable
	{
		fermerCase(C, O, &NBO, c[0], G, c[1]);   // Fermeture de la case
		ecrireGrille(G);   // Affichage de la grille
		if (NBO != 0)
			ecrireCand(C, NBO);   // Affichage des candidats s'il en reste
	}
	if (NBO != 0)
		printf("\nLa grille n'est pas finissable.\n");   // S'il reste encore des candidats, la grille n'est pas finissable
	else
		printf("\nLa grille est complété.\n");   // La grille est résolue
}
