/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:21:03 by amerelo           #+#    #+#             */
/*   Updated: 2016/01/31 16:37:45 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void		rand_num(t_env *env)
{
	int		x;
	time_t	t;

	srand((unsigned)time(&t));
	x = rand() % env->board_size;
	while (env->board[x] != 0)
		x = rand() % env->board_size;
	if ((rand() % 10) < 9)
		env->board[x] = 2;
	else
		env->board[x] = 4;
}
