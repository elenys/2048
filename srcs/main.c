/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:21:03 by amerelo           #+#    #+#             */
/*   Updated: 2016/01/31 16:59:30 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	init_env(t_env *env)
{
	env->cont = 0;
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
	return (0);
}
