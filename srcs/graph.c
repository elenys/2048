/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 13:50:47 by bmartins          #+#    #+#             */
/*   Updated: 2016/01/31 15:10:20 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void		exit_game(t_env *env)
{
	endwin();
	free(env->board);
	exit(0);
}

static void init_graph(void)
{
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
}


static void	get_key(t_env *env, int ch)
{
	if (ch == KEY_LEFT)
		ft_move_left(env->board, env->board_size, 0);
	else if (ch == KEY_RIGHT)
		ft_move_right(env->board, env->board_size);
	else if (ch == KEY_UP)
		ft_move_up(env->board, env->board_size);
	else if (ch == KEY_DOWN)
		ft_move_down(env->board, env->board_size, 0);
	else if (ch == 410)
		check_size(env);
	else if (ch == 27)
		exit_game(env);
}

void	game_loop(t_env *env)
{
	init_graph();
	while (1)
	{
		print_board(env);
		get_key(env, getch());
//		rand_num(env);
	}
}
