/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:56:27 by alabalet          #+#    #+#             */
/*   Updated: 2020/10/20 16:25:36 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int cpt;

	cpt = 0;
	if (min >= max)
	{
		range[0] = 0;
		return (0);
	}
	else
	{
		*range = malloc((max - min) * sizeof(int));
		if (!*range)
		{
			*range = 0;
			return (-1);
		}
		while (min + cpt < max)
		{
			(*range)[cpt] = min + cpt;
			cpt++;
		}
	}
	return (max - min);
}
