/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:56:27 by alabalet          #+#    #+#             */
/*   Updated: 2020/10/22 12:03:41 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int cpt;
	int *result;

	cpt = 0;
	if (min >= max)
		return (0);
	result = malloc((max - min) * sizeof(int));
	while (min + cpt < max)
	{
		result[cpt] = min + cpt;
		cpt++;
	}
	return (result);
}
