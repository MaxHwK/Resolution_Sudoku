#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>

# define BUF_SIZE 1024
# define bool int
# define TRUE 1
# define FALSE 0

typedef struct
{
	int x;
	int y;
}				Case;

typedef struct
{
	int nbc;
	int *tab;
}				Cand;

void	ecrireGrille(int **G);
void	ecrireCand(Cand C[9][9], int NBO);
void	initJeu(Cand C[9][9], int *NBO, Case *O, int **G);
void	fermerCase(Cand C[9][9], Case *O, int *NBO, int c, int **G, int nb);
void	fermerGrille(Cand C[9][9], Case *O, int NBO, int **G);

int		ft_strlen(char *str);
int		*rechCaseUnique(Cand C[9][9], Case *O, int NBO);
int		appartient(Cand C[9][9], int x, int y, int nb);
int		**lireGrille(char *nom);

bool	estCand(int **G, int x, int y, int nb);
bool	estCandUnique(Cand C[9][9], int x, int y, int nb);

char	*ft_strcpy(char *src, char *dest);
char	*ft_strlowercase(char *str);

#endif
