/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:21:03 by amerelo           #+#    #+#             */
/*   Updated: 2016/01/31 18:19:25 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	init_env(t_env *env)
{
	env->up = 0;
	env->max = 0;
	env->cont = 0;
	env->left = 0;
	env->down = 0;
	env->right = 0;
	env->board_size = ft_power_x(TAB_SIZE);
	env->board = ft_creat_tab(TAB_SIZE);
	rand_num(env);
	rand_num(env);
}

int			main(void)
{
	t_env	env;

	init_env(&env);
	game_loop(&env);
	free(env.board);
	endwin();
	return (0);
}
