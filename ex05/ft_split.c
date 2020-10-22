/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 20:50:55 by alabalet          #+#    #+#             */
/*   Updated: 2020/10/22 11:45:10 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_isin(char c, char *str);
int		ft_wc(char *str, char *charset);
char	*ft_parse_word(char *str, char *sep, int *cpt);
char	**ft_split(char *str, char *charset);

int		ft_isin(char c, char *str)
{
	int cpt;

	cpt = 0;
	while (str[cpt])
	{
		if (c == str[cpt++])
			return (1);
	}
	return (0);
}

int		ft_wc(char *str, char *charset)
{
	int cpt;
	int wc;

	wc = 0;
	cpt = 0;
	if (charset[0] == '\0')
		return (!(str[0] == '\0'));
	while (ft_isin(str[cpt], charset))
		cpt++;
	while (str[cpt])
	{
		while (!ft_isin(str[cpt], charset))
			cpt++;
		wc++;
		while (ft_isin(str[cpt], charset))
			cpt++;
	}
	return (wc);
}

char	*ft_parse_word(char *str, char *sep, int *cpt)
{
	int		len;
	char	*ret;

	len = 0;
	while (str[*cpt + len] && !ft_isin(str[*cpt + len], sep))
		len++;
	ret = malloc(len + 1);
	len = 0;
	while (str[*cpt + len] && !ft_isin(str[*cpt + len], sep))
	{
		ret[len] = str[*cpt + len];
		len++;
	}
	ret[len] = '\0';
	*cpt += len;
	return (ret);
}

char	**ft_split(char *str, char *charset)
{
	int		cpt_tab;
	int		cpt_str;
	int		wc;
	char	**ret;

	wc = ft_wc(str, charset);
	ret = malloc(sizeof(char *) * (wc + 1));
	cpt_str = 0;
	cpt_tab = 0;
	while (cpt_tab < wc)
	{
		while (ft_isin(str[cpt_str], charset))
			cpt_str++;
		ret[cpt_tab++] = ft_parse_word(str, charset, &cpt_str);
	}
	ret[cpt_tab] = 0;
	return (ret);
}
