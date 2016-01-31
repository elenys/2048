/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_down.c                                    :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:21:03 by amerelo           #+#    #+#             */
/*   Updated: 2016/01/30 13:21:07 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int		t_col(int *tab, int x, int tab_s)
{
	int i;

	i = (tab_s - 1);
	i -= TAB_SIZE + (3 - (x % TAB_SIZE));
	while(i > x)
	{
		if (tab[i] != 0 && tab[i] != tab[x])
			return (0);
		i -= TAB_SIZE;
	}
	return (1);
}


static void		ft_move_down2(int *tab, int x, int *on , int tab_s)
{
	int i;

	i = (tab_s - 1) - (3 - (x % TAB_SIZE));
	while(i > x)
	{
		if (tab[i] != 0 && tab[i] == tab[x] && on[0] == 0 && t_col(tab, x, tab_s))
		{
			tab[i] += tab[x];
			tab[x] = 0;
			on[0] = 1;
			on[1] = 1;
		}
		else if (tab[i] == 0)
		{
			tab[i] = tab[x];
			tab[x] = 0;
			on[0] = 0;
			on[1] = 1;
		}
		i -= TAB_SIZE;
	}
}

int		ft_move_down(int *tab, int tab_s, int x, t_env *env)
{
	int i;
	int t;
	int on[2];

	i = TAB_SIZE;
	t = 0;
	while(i > 0)
	{
		x = 11 - t;
		on[0] = 0;
		while (x > -1)
		{
			if (tab[x] != 0)
				ft_move_down2(tab, x, on, tab_s);
			if ((x / TAB_SIZE) == 0 && tab[x + TAB_SIZE] == tab[x])
			{
				tab[x + TAB_SIZE] += tab[x];
				tab[x] = 0;
			}
			x -= TAB_SIZE;
		}
		--i;
		++t;
	}
	return (on[1]);
}


// |2||4||4||4| 3 0
// |2||0||4||4| 2 1
// |8||9||10||11| 1 2
// |0||2||2||0| 0 3

