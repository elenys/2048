/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 13:50:47 by bmartins          #+#    #+#             */
/*   Updated: 2016/01/31 19:24:47 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void		reset_touch(t_env *env)
{
	env->up = 0;
	env->down = 0;
	env->left = 0;
	env->right = 0;
}

static void		init_graph(void)
{
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
}

static int		get_key(t_env *env, int ch)
{
	int move;

	move = 0;
	if (ch == KEY_LEFT)
		move = ft_move_left(env->board, env->board_size, 0, env);
	else if (ch == KEY_RIGHT)
		move = ft_move_right(env->board, env->board_size, env);
	else if (ch == KEY_UP)
		move = ft_move_up(env->board, env->board_size, env);
	else if (ch == KEY_DOWN)
		move = ft_move_down(env->board, env->board_size, 0, env);
	else if (ch == 410)
		check_size();
	else if (ch == 27)
		env->exit = 1;
	return (move);
}

void			game_loop(t_env *env)
{
	init_graph();
	ft_test(env);
	while (env->exit == 0)
	{
		print_board(env);
		if (get_key(env, getch()))
		{
			ft_test(env);
			rand_num(env);
			reset_touch(env);
		}
		if (env->left && env->right && env->up && env->down)
		{
			ft_defeat();
			env->exit = 1;
		}
	}
}
