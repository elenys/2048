/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:21:03 by amerelo           #+#    #+#             */
/*   Updated: 2016/01/30 13:21:07 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int			*ft_creat_tab(int size)
{
	int	*final_tab;
	int	x;

	x = 0;
	if (size == 0)
		return (NULL);
	size = ft_power_x(size);
	final_tab = (int *)malloc(sizeof(int ) * (size + 1));
	if (!final_tab)
		return(NULL);
	final_tab[size + 1] = '\0';
	while (x < size)
	{
		final_tab[x] = 0;
		x++;
	}
	return (final_tab);
}
