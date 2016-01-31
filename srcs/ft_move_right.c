/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:21:03 by amerelo           #+#    #+#             */
/*   Updated: 2016/01/31 19:08:15 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	t_line(int *tab, int *tmpx, int s)
{
	int i;

	i = (s + *tmpx);
	--i;
	while (i > s)
	{
		if (tab[i] != 0)
			return (0);
		--i;
	}
	return (1);
}

static void	ft_move_right2(t_env *env, int s, int *tmpx, int *on)
{
	if ((env->board[s + *tmpx]) == 0)
	{
		env->board[s + *tmpx] = env->board[s];
		env->board[s] = 0;
		on[0] = 0;
		on[2] = 1;
	}
	else if ((env->board[s + *tmpx]) == env->board[s] && on[1] == 0 &&
			t_line(env->board, tmpx, s))
	{
		env->board[s + *tmpx] += env->board[s];
		env->board[s] = 0;
		on[0] = 0;
		on[1] = 1;
		on[2] = 1;
		env->max = (env->board[s + *tmpx] > env->max) ?
			env->board[s + *tmpx] : env->max;
	}
	else if ((env->board[s + *tmpx]) == env->board[s] && on[1] == 1)
		on[1] = 0;
	env->right = 1;
}

int			ft_move_right(int *tab, int tab_s, t_env *env)
{
	int tmpx;
	int on[3];

	on[2] = 0;
	while (tab_s >= 0)
	{
		if (tab[tab_s] != 0)
		{
			tmpx = (tab_s % TAB_SIZE);
			tmpx = 3 - tmpx;
			on[0] = 1;
			while (on[0] && tmpx != 0)
			{
				ft_move_right2(env, tab_s, &tmpx, on);
				--tmpx;
			}
		}
		--tab_s;
		on[1] = ((tab_s / TAB_SIZE) != ((tab_s + 1) / TAB_SIZE)) ? 0 : on[1];
	}
	return (on[2]);
}
