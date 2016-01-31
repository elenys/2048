/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartins <bmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 10:33:14 by bmartins          #+#    #+#             */
/*   Updated: 2016/01/31 17:03:18 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "libft.h"
# include <curses.h>
# include <stdlib.h>
# include <time.h>



# define TAB_SIZE 4
# define WIN_VALUE 8

typedef struct		s_env
{
	int				*board;
	int				board_size;
	int				*last_board;
	int				left;
	int				right;
	int				up;
	int				down;
	int				max;
	int				cont;
	WINDOW			*win;
}					t_env;


int					ft_move_left(int *tab, int tab_s, int x, t_env *env);
int					ft_move_right(int *tab, int tab_s, t_env *env);
int					ft_move_up(int *tab, int x, t_env *env);
int					ft_move_down(int *tab, int tab_s, int x, t_env *env);
void				ft_check_status(t_env *env);

int					ft_power_x(int x);
int					winv_valid(t_env *env);
int					*ft_creat_tab(int size);


void				check_size(void);
void				rand_num(t_env *env);
void				game_loop(t_env *env);
void				print_board(t_env *env);
#endif
