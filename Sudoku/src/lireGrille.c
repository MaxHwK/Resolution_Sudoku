#include "header.h"

int		**lireGrille(char *nom)
{
	FILE	*fichier;      // Fichier logique
	int		**G;           // Tableau
	int		c;             // Caractère lu
	int		i;             // Compteur
	int		j;             // Compteur
	int		nb1;           // Ligne              |
	int		nb2;           // Colonne            |=> Lecture de fichier
	int		nb3;           // Valeur de la case  |
                   /*   Initialisation du tableau   */
	if (!(G = (int **)malloc(sizeof(int *) * 9)))
	{
		printf("Mémoire insuffisante\n");
		return (NULL);
	}
	for (i = 0; i < 9; i++)
		if (!(G[i] = (int *)malloc(sizeof(int) * 9)))
		{
			printf("Mémoire insuffisante\n");
			return (NULL);
		}
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
			G[i][j] = 0;
                   /*   Ouverture du fichier   */
	if (!(fichier = fopen(nom, "r")))
	{
		printf("Fichier inexistant\n");
		return (NULL);
	}
                   /*   Lecture du fichier   */
	nb1 = nb2 = nb3 = -1;
	while ((c = fgetc(fichier)) != EOF)   // Tant qu'on n'est pas à la fin du fichier
	{
		while (c == ' ' || c == '\n')   // On passe les espaces et retour à la ligne
			c = fgetc(fichier);
		if (nb1 == -1)   // Si nb1, nb2 ou nb3 sont à -1, c'est qu'on a pas encore lu les 3 valeurs de la ligne
			nb1 = c - '0';   // On enlève '0' pour retrouver la valeur décimal du caractère
		else if (nb2 == -1)
			nb2 = c - '0';
		else if (nb3 == -1)
			nb3 = c - '0';
		else
		{
			G[nb1][nb2] = nb3;   // On affecte la valeur lue à la case
			nb1 = nb2 = nb3 = -1;   // On réinitialise les valeurs
		}
	}
                   /*   Fermeture du fichier   */
	fclose(fichier);
	return (G);
}
