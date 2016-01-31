/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:21:03 by amerelo           #+#    #+#             */
/*   Updated: 2016/01/30 13:21:07 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int		t_col(int *tab, int x)
{
	int i;

	i = (x % TAB_SIZE);
	i += TAB_SIZE;
	while(i < x)
	{
		if (tab[i] != 0 && tab[i] != tab[x])
			return (0);
		i += TAB_SIZE;
	}
	return (1);
}

static void		ft_move_up2(int *tab, int x, int *on)
{
	int i;

	i = (x % TAB_SIZE);
	while(i < x)
	{
		if (tab[i] != 0 && tab[i] == tab[x] && 	*on == 0 && t_col(tab, x))
		{
				tab[i] += tab[x];
				tab[x] = 0;
				*on = 1;
		}
		else if (tab[i] == 0)
		{
			tab[i] = tab[x];
			tab[x] = 0;
			*on = 0;
		}
		i += TAB_SIZE;
	}
}

void		ft_move_up(int *tab, int x)
{
	int i;
	int on;

	i = 0;
	while(i < TAB_SIZE)
	{
		x = TAB_SIZE + i;
		on = 0;
		while (x < TAB_SIZE * TAB_SIZE)
		{
			if (tab[x] != 0)
				ft_move_up2(tab, x, &on);
			if ((x / TAB_SIZE) == 3 && tab[x - TAB_SIZE] == tab[x])
			{
				tab[x - TAB_SIZE] += tab[x];
				tab[x] = 0;
			}
			x += TAB_SIZE;
		}
		i++;
	}
}
