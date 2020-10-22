/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:30:34 by alabalet          #+#    #+#             */
/*   Updated: 2020/10/22 12:39:48 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_lenbase(char *base)
{
	int		cpt;
	int		ref[255];

	cpt = 0;
	while (cpt < 255)
		ref[cpt++] = 0;
	cpt = 0;
	while (base[cpt])
	{
		if (ref[(int)base[cpt]])
			return (0);
		if (base[cpt] == '+' || base[cpt] == '-')
			return (0);
		ref[(int)base[cpt++]] = 1;
	}
	return (cpt);
}
