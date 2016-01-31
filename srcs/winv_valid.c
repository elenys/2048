/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winv_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:21:03 by amerelo           #+#    #+#             */
/*   Updated: 2016/01/31 16:16:30 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	print_victory(void)
{
	clear();
	mvprintw(LINES / 2, COLS / 2 - 4, "YOU WIN!");
	mvhline(LINES / 2 - 2, COLS / 2 - 10, 0, 21);
	mvvline(LINES / 2 - 1, COLS / 2 - 10, 0, 4);
	mvvline(LINES / 2 - 1, COLS / 2 + 10, 0, 4);
	mvhline(LINES / 2 + 2, COLS / 2 - 10, 0, 21);
	refresh();
	sleep(2);
}

int			winv_valid(t_env *env)
{
	int a;
	int b;

	a = WIN_VALUE;
	if (a == 2)
		env->cont = 1;
	while (a > 2)
	{
		b = a % 2;
		a = a / 2;
		if (b != 0)
			env->cont = 1;
		if (a == 2)
			return(0);
	}
	if (env->cont == 1)
		print_victory();
	return(0);
}
