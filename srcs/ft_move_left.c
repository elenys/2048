/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:21:03 by amerelo           #+#    #+#             */
/*   Updated: 2016/01/30 13:21:07 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int		t_line(int *tab, int *tmpx, int x)
{
	int i;

	i = (x - *tmpx);
	++i;
	while(i < x)
	{
		if (tab[i] != 0)
			return (0);
		++i;
	}
	return (1);
}

static void		ft_move_left2(int *tab, int x, int *tmpx, int *on)
{
	if ((tab[x - *tmpx]) == 0)
	{
		tab[x - *tmpx] = tab[x];
		tab[x] = 0;
		on[0] = 0;
		on[1] = 0;
	}
	else if ((tab[x - *tmpx]) == tab[x] && on[1] == 0 && t_line(tab, tmpx, x))
	{
		tab[x - *tmpx] += tab[x];
		tab[x] = 0;
		on[0] = 0;
		on[1] = 1;
	}
	else if ((tab[x - *tmpx]) == tab[x] && on[1] == 1)
		on[1] = 0;
}

void		ft_move_left(int *tab, int tab_s, int x)
{
	int tmpx;
	int on[2];

	on[1] = 0;
	while(x < tab_s)
	{
		if (tab[x] != 0)
		{
			tmpx = (x % TAB_SIZE);
			on[0] = 1;
			while (on[0] && tmpx != 0)
			{
				ft_move_left2(tab, x, &tmpx, on);
				--tmpx;
			}
		}
		++x;
		on[1] = ((x / TAB_SIZE) != ((x - 1) / TAB_SIZE)) ? 0 : on[1];
	}
}
