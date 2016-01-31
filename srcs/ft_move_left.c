/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:21:03 by amerelo           #+#    #+#             */
/*   Updated: 2016/01/31 19:12:35 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	t_line(int *tab, int *tmpx, int x)
{
	int i;

	i = (x - *tmpx);
	++i;
	while (i < x)
	{
		if (tab[i] != 0)
			return (0);
		++i;
	}
	return (1);
}

static void	ft_move_left2(t_env *env, int x, int *tmpx, int *on)
{
	if ((env->board[x - *tmpx]) == 0)
	{
		env->board[x - *tmpx] = env->board[x];
		env->board[x] = 0;
		on[0] = 0;
		on[1] = 0;
		on[2] = 1;
	}
	else if ((env->board[x - *tmpx]) == env->board[x] && on[1] == 0 &&
			t_line(env->board, tmpx, x))
	{
		env->board[x - *tmpx] += env->board[x];
		env->board[x] = 0;
		on[0] = 0;
		on[1] = 1;
		on[2] = 1;
		env->max = (env->board[x - *tmpx] > env->max) ?
			env->board[x - *tmpx] : env->max;
	}
	else if ((env->board[x - *tmpx]) == env->board[x] && on[1] == 1)
		on[1] = 0;
	env->left = 1;
}

int			ft_move_left(int *tab, int tab_s, int x, t_env *env)
{
	int tmpx;
	int on[3];

	on[1] = 0;
	on[2] = 0;
	while (x < tab_s)
	{
		if (tab[x] != 0)
		{
			tmpx = (x % TAB_SIZE);
			on[0] = 1;
			while (on[0] && tmpx != 0)
			{
				ft_move_left2(env, x, &tmpx, on);
				--tmpx;
			}
		}
		++x;
		on[1] = ((x / TAB_SIZE) != ((x - 1) / TAB_SIZE)) ? 0 : on[1];
	}
	return (on[2]);
}
