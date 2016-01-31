/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:21:03 by amerelo           #+#    #+#             */
/*   Updated: 2016/01/31 19:03:59 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void		print_victory(void)
{
	clear();
	mvprintw(LINES / 2, COLS / 2 - 4, "YOU WIN!");
	mvhline(LINES / 2 - 2, COLS / 2 - 10, 0, 21);
	mvvline(LINES / 2 - 1, COLS / 2 - 10, 0, 4);
	mvvline(LINES / 2 - 1, COLS / 2 + 10, 0, 4);
	mvhline(LINES / 2 + 2, COLS / 2 - 10, 0, 21);
	refresh();
	sleep(3);
}

void			ft_test(t_env *env)
{
	if (env->max == WIN_VALUE && env->cont == 0)
	{
		env->cont = 1;
		print_victory();
	}
	else if (env->max == 8192)
	{
		env->cont = 1;
		print_victory();
	}
}
