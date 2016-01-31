/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 16:27:46 by bmartins          #+#    #+#             */
/*   Updated: 2016/01/31 16:27:48 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	check_size(void)
{
	if (COLS < 21 || LINES < 10)
	{
		while (COLS < 21 || LINES < 10)
		{
			clear();
			mvprintw(0, 0, "Insufisant win size");
			refresh();
			usleep(50000);
		}
	}
}
