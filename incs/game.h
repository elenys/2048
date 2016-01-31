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


typedef struct		s_env
{
	int				board_size;
	int				**board;
	WINDOW			*win;
}					t_env;

void				check_size(t_env *env);
void				print_board(t_env *env);

#endif
