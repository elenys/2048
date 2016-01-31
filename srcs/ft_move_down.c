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


static void		ft_move_down2(t_env *env, int x, int *on , int tab_s)
{
	int i;

	i = (tab_s - 1) - (3 - (x % TAB_SIZE));
	while(i > x)
	{
		if (env->board[i] != 0 && env->board[i] == env->board[x] && 
			on[0] == 0 && t_col(env->board, x, tab_s))
		{
			env->board[i] += env->board[x];
			env->board[x] = 0;
			on[0] = 1;
			on[1] = 1;
			env->max = (env->board[i] > env->max) ? env->board[i] : env->max;
		}
		else if (env->board[i] == 0)
		{
			env->board[i] = env->board[x];
			env->board[x] = 0;
			on[0] = 0;
			on[1] = 1;
		}
		env->down = 1;
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
				ft_move_down2(env, x, on, tab_s);
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
