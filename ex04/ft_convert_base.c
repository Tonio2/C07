/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 11:35:53 by alabalet          #+#    #+#             */
/*   Updated: 2020/10/22 12:39:39 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_lenbase(char *base);
int		ft_indexof(char c, char *str);
int		ft_atoi_base(char *str, char *base, int len_base);
char	*ft_createstr_base(int nb, char *base, int len_base);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int		ft_indexof(char c, char *str)
{
	int cpt;

	cpt = 0;
	while (str[cpt])
	{
		if (str[cpt] == c)
			return (cpt);
		cpt++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base, int len_base)
{
	int cpt;
	int result;
	int cur_index;
	int sign;

	sign = 1;
	cpt = 0;
	result = 0;
	while (str[cpt] == ' ' || (9 <= str[cpt] && str[cpt] <= 13))
		cpt++;
	while (str[cpt] == '+' || str[cpt] == '-')
		sign *= (str[cpt++] == '-') ? -1 : 1;
	while (str[cpt])
	{
		cur_index = ft_indexof(str[cpt], base);
		if (cur_index == -1)
			return (result);
		result = result * len_base + cur_index;
		cpt++;
	}
	return (sign * result);
}

char	*ft_createstr_base(int nb, char *base, int len_base)
{
	int		cpt;
	char	result[40];
	char	*ret;
	int		sign;
	int		len;

	if (nb == 0)
		return ("0");
	cpt = 0;
	sign = (nb < 0) ? -1 : 1;
	while (nb)
	{
		result[cpt++] = base[sign * (nb % len_base)];
		nb /= len_base;
	}
	if (sign == -1)
		result[cpt++] = '-';
	ret = malloc(cpt);
	len = cpt;
	cpt = -1;
	while (++cpt < len)
		ret[cpt] = result[len - cpt - 1];
	ret[cpt] = '\0';
	return (ret);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		len_base_from;
	int		len_base_to;
	int		nb;
	char	*result;

	len_base_from = ft_lenbase(base_from);
	len_base_to = ft_lenbase(base_to);
	if (len_base_from < 2 || len_base_to < 2)
		return (0);
	nb = ft_atoi_base(nbr, base_from, len_base_from);
	result = ft_createstr_base(nb, base_to, len_base_to);
	return (result);
}
