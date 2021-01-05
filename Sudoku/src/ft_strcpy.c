#include "header.h"

char	*ft_strcpy(char *src, char *dest)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(src);
	dest = (char*)malloc(sizeof(char) * len);
	while (i < len - 1)   // Copiage de dest dans src
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
