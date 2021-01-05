#include "header.h"

int		ft_strlen(char *str)
{
	int i;
                      /* Calcul de la longueur d'une chaîne */
	i = 0;
	while (str[i])
		i++;
	return (i);
}
