/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 10:23:06 by alabalet          #+#    #+#             */
/*   Updated: 2020/10/21 10:23:22 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *src)
{
	int cpt;

	cpt = 0;
	while (src[cpt])
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
	dest[cpt] = '\0';
}

char	*ft_strdup(char *src)
{
	int		len_src;
	char	*dest;

	len_src = ft_strlen(src);
	dest = malloc(len_src + 1);
	ft_strcpy(dest, src);
	return (dest);
}
