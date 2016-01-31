/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:21:03 by amerelo           #+#    #+#             */
/*   Updated: 2016/01/30 13:21:07 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int		t_line(int *tab, int *tmpx, int s)
{
	int i;

	i = (s + *tmpx);
	--i;
	while(i > s)
	{
		if (tab[i] != 0)
			return (0);
		--i;
	}
	return (1);
}

static void		ft_move_right2(int *tab, int s, int *tmpx, int *on)
{
	if ((tab[s + *tmpx]) == 0)
	{
		tab[s + *tmpx] = tab[s];
		tab[s] = 0;
		on[0] = 0;
		on[2] = 1;
	}
	else if ((tab[s + *tmpx]) == tab[s] && on[1] == 0 && t_line(tab, tmpx, s))
	{
		tab[s + *tmpx] += tab[s];
		tab[s] = 0;
		on[0] = 0;
		on[1] = 1;
		on[2] = 1;
	}
	else if ((tab[s + *tmpx]) == tab[s] && on[1] == 1)
		on[1] = 0;
}

int		ft_move_right(int *tab, int tab_s, t_env *env)
{
	int tmpx;
	int on[3];

	on[2] = 0;
	while(tab_s >= 0)
	{
		if (tab[tab_s] != 0)
		{
			tmpx = (tab_s % TAB_SIZE);
			tmpx = 3 - tmpx;
			on[0] = 1;
			while (on[0] && tmpx != 0)
			{
				ft_move_right2(tab, tab_s, &tmpx, on);
				--tmpx;
			}
		}
		--tab_s;
		on[1] = ((tab_s / TAB_SIZE) != ((tab_s + 1) / TAB_SIZE)) ? 0 : on[1];
	}
	return (on[2]);
}
