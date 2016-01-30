/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartins <bmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 13:04:56 by bmartins          #+#    #+#             */
/*   Updated: 2014/11/16 16:45:27 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_cptdigit(int n)
{
	size_t			dig;

	dig = 1;
	while (n /= 10)
		dig++;
	return (dig);
}

char				*ft_itoa(int n)
{
	size_t			dig;
	size_t			ncp;
	char			*str;

	ncp = n;
	dig = ft_cptdigit(n);
	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	if (n < 0)
	{
		dig++;
		ncp = -n;
	}
	if (!(str = ft_strnew(dig)))
		return (NULL);
	str[--dig] = ncp % 10 + '0';
	while (ncp /= 10)
		str[--dig] = ncp % 10 + '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
