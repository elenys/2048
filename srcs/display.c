/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 13:41:09 by bmartins          #+#    #+#             */
/*   Updated: 2016/01/31 14:26:52 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void		print_v_line(void)
{
	int			i;
	int			width;
	int			hight;

	i = 0;
	width = COLS / 4;
	if (COLS % 4 == 0)
		width -= 1;
	hight = (LINES / 4) * 4;
	if (LINES % 4 == 0)
		hight -= 4;
	while (i <= 4)
	{
		mvvline(0, width * i, 0, hight);
		i++;
	}
	refresh();
}

static void		print_h_line(void)
{
	int			i;
	int			width;
	int			hight;

	i = 0;
	hight = LINES / 4;
	if (LINES % 4 == 0)
		hight -= 1;
	width = (COLS / 4) * 4;
	if (COLS % 4 == 0)
		width -= 3;
	else
		width += 1;
	while (i <= 4)
	{
		mvhline(i * hight, 0, 0, width);
		i++;
	}
	refresh();
}

static int		size_nb(int nb)
{
	return (ft_strlen(ft_itoa(nb)) / 2);
}

static void		print_value(int *tab)
{
	int			i;
	int			width;
	int			hight;

	i = 0;
	hight = LINES / 4;
	if (LINES % 4 == 0)
		hight -= 1;
	width = (COLS / 4);
	if (COLS % 4 == 0)
		width -= 1;
	while (i < 16)
	{
		if (tab[i] != 0)
				mvprintw(hight * (i / 4) + LINES / 8, width * (i % 4) + 1 + COLS / 8 -
					size_nb(tab[i]), "%d", tab[i]);
		i++;
	}
	refresh();
}

void			print_board(t_env *env)
{
	clear();
	print_value(env->board);
	print_v_line();
	print_h_line();
	refresh();
}
