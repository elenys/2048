/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:21:03 by amerelo           #+#    #+#             */
/*   Updated: 2016/01/31 16:14:38 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdio.h>

int main (void)
{
	t_env	env;

	if (!winv_valid())
		exit_game(env);
	env.board_size = ft_power_x(TAB_SIZE);
	env.board = ft_creat_tab(TAB_SIZE);
	env.board[0] = 2;
	env.board[8] = 2;
	env.board[3] = 2;
	env.board[15] = 4;
	env.cont = 0;
	game_loop(&env);
	free(env.board);
	return (0);
}
