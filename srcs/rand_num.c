/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:21:03 by amerelo           #+#    #+#             */
/*   Updated: 2016/01/30 13:21:07 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void		rand_num(int *tab, int tab_s)
{
	int x;
	time_t t;

	srand((unsigned) time(&t));

	x = rand() % tab_s;
	while(tab[x] != 0)
		x = rand() % tab_s;
	if ((rand() % 10) < 9)
		tab[x] = 2;
	else
		tab[x] = 4;
}