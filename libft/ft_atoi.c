/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartins <bmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:30:24 by bmartins          #+#    #+#             */
/*   Updated: 2015/06/11 17:54:15 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	neg;

	i = 0;
	n = 0;
	neg = 0;
	while ((str[i] == ' ') || ((str[i] >= '\t') && (str[i] <= '\r')))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg = 1;
		i++;
	}
	while (ft_isnum(str[i]))
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	if (neg)
		n = -n;
	return (n);
}
