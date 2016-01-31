/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartins <bmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 10:33:14 by bmartins          #+#    #+#             */
/*   Updated: 2016/01/30 12:12:46 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
#define GAME_H

# include "libft.h"
# include <curses.h>
# include <stdlib.h>
# include <time.h>

enum e_const
{
	WIN_VALUE = 2048,
	TAB_SIZE = 4
};

int			*ft_creat_tab(int size);
void		rand_num(int *tab, int tab_s);
void		ft_move_left(int *tab, int tab_s, int x);
void		ft_move_right(int *tab, int tab_s);
void		ft_move_up(int *tab, int x);
void		ft_move_down(int *tab, int tab_s, int x);
int			ft_power_x(int x);
int			winv_valid(void);

#endif
