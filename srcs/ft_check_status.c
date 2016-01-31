/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:21:03 by amerelo           #+#    #+#             */
/*   Updated: 2016/01/30 13:21:07 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// static void	print_lose(t_env *env)
// {
// 	clear();
// 	mvprintw(LINES / 2, COLS / 2 - 4, "YOU LOSE");
// 	mvhline(LINES / 2 - 2, COLS / 2 - 10, 0, 21);
// 	mvvline(LINES / 2 - 1, COLS / 2 - 10, 0, 4);
// 	mvvline(LINES / 2 - 1, COLS / 2 + 10, 0, 4);
// 	mvhline(LINES / 2 + 2, COLS / 2 - 10, 0, 21);
// 	refresh();
// 	sleep(5);
// 	exit_game(env);
// }

void ft_check_status(t_env *env)
{
	int x;
	int stat;

	x = 0;
	while (x < 16)
	{
		stat = 0;
		if ((0 >= (x + 1) && (x + 1) < 16) && env->board[x] != env->board[x + 1])
			stat += 1;

		if ((0 >= (x - 1) && (x - 1) < 16) && env->board[x] != env->board[x - 1])
			stat += 1;
		
		if ((0 >= (x + 4) && (x + 4) < 16) && env->board[x] != env->board[x + 4])
			stat += 1;

		if ((0 >= (x - 4) && (x - 4) < 16) && env->board[x] != env->board[x - 4])
			stat += 1;
		x++;
	}
// 	if (!stat)
// 		print_lose(env);
}
