#include <stdlib.h>

int		ft_strlen(char *src)
{
	int cpt;

	cpt = 0;
	while(src[cpt])
		cpt++;
	return (cpt);
}

void	ft_strcpy(char *dest, char *src)
{
	int cpt;

	cpt = 0;
	while (src[cpt])
	{
		dest[cpt] = src[cpt];
		cpt++;
	}
}

char	*ft_strdup(char *src)
{
	int		len_src;
	char	*dest;

	len_src = ft_strlen(src);
	dest = malloc(len_src);
	ft_strcpy(dest, src);
	return (dest);
}
