/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartins <bmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 14:17:43 by bmartins          #+#    #+#             */
/*   Updated: 2015/06/11 15:49:46 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(const char *s, char c)
{
	size_t		i;
	size_t		occ;

	i = 0;
	occ = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			occ++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (occ);
}

static char		*ft_addword(const char *s, char c, size_t i)
{
	size_t		len;
	char		*str;

	len = i;
	while (s[len] && s[len] != c)
		len++;
	if (!(str = ft_strnew(len - i)))
		return (NULL);
	str = ft_strsub(s, i, len - i);
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		i;
	size_t		j;
	char		**tab;

	j = 0;
	i = 0;
	tab = NULL;
	if (!s)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * ft_countword(s, c) + 1)))
		return (NULL);
	while (j < ft_countword(s, c))
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			tab[j++] = ft_addword(s, c, i);
		while (s[i] != c && s[i])
			i++;
	}
	tab[j] = 0;
	return (tab);
}
