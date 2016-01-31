/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:21:03 by amerelo           #+#    #+#             */
/*   Updated: 2016/01/31 19:38:32 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void init_max(t_env *env)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (env->board[i] > env->max)
			env->max = env->board[i];
		i++;
	}
}

static void	init_env(t_env *env)
{
	env->up = 0;
	env->cont = 0;
	env->left = 0;
	env->down = 0;
	env->right = 0;
	env->board_size = ft_power_x(TAB_SIZE);
	env->board = ft_creat_tab(TAB_SIZE);
	rand_num(env);
	rand_num(env);
	init_max(env);
}

int			main(void)
{
	t_env	env;

	init_env(&env);
	if (!winv_valid(&env))
		ft_putendl("Wrong Win Value");
	else
	{
		game_loop(&env);
		free(env.board);
		endwin();
	}
	return (0);
}
