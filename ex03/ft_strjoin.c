/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:51:52 by alabalet          #+#    #+#             */
/*   Updated: 2020/10/21 10:50:27 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strslen(int size, char **strs, char *sep)
{
	int cpt;
	int cpt2;
	int len;
	int len_sep;

	cpt = 0;
	while (sep[cpt])
		cpt++;
	len_sep = cpt;
	cpt = 0;
	len = 0;
	while (cpt < size)
	{
		cpt2 = 0;
		while (strs[cpt][cpt2++])
			len++;
		len += len_sep;
		cpt++;
	}
	if (len > 0)
		len -= len_sep;
	return (len);
}

void	ft_strcat(char *dest, char *src)
{
	int cpt;
	int cpt2;

	cpt = 0;
	cpt2 = 0;
	while (dest[cpt])
		cpt++;
	while (src[cpt2])
		dest[cpt++] = src[cpt2++];
	dest[cpt] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		cpt;
	int		len;

	cpt = 0;
	len = ft_strslen(size, strs, sep);
	result = malloc(len * sizeof(char) + 1);
	result[0] = '\0';
	while (cpt < size)
	{
		ft_strcat(result, strs[cpt]);
		if (cpt < size - 1)
			ft_strcat(result, sep);
		cpt++;
	}
	return (result);
}
