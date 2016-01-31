/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_defeat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:21:03 by amerelo           #+#    #+#             */
/*   Updated: 2016/01/31 16:36:57 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_defeat(void)
{
	clear();
	mvprintw(LINES / 2, COLS / 2 - 4, "YOU LOOSE");
	mvhline(LINES / 2 - 2, COLS / 2 - 10, 0, 21);
	mvvline(LINES / 2 - 1, COLS / 2 - 10, 0, 4);
	mvvline(LINES / 2 - 1, COLS / 2 + 10, 0, 4);
	mvhline(LINES / 2 + 2, COLS / 2 - 10, 0, 21);
	refresh();
	sleep(3);
}
