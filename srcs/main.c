/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:21:03 by amerelo           #+#    #+#             */
/*   Updated: 2016/01/30 13:21:07 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdio.h>

int main (void)
{

	// if (winv_valid())
	// 	printf("OK\n");
	// else
	// 	printf("NO\n");

	int *tab;
	int tab_s;
	int x;

	x = 0;
	tab_s = ft_power_x(TAB_SIZE);
	tab = ft_creat_tab(TAB_SIZE);

	// rand_num(tab, tab_s);
	// rand_num(tab, tab_s);

	tab[3]	= 2;
	// tab[1]	= 5;
	// tab[2]	= 2;
	tab[7]	= 3;

	tab[11]	= 3;
	// tab[9]	= 2;
	// tab[11]	= 4;
	tab[15]	= 3;
	// tab[12]	= 1;
	// tab[14]	= 2;
	// tab[15]	= 2;
	// printf("%d\n", rand() % tab_s);
	while (x < tab_s)
	{
		if (x % 4 == 0)
			printf("\n");
		printf("%d", tab[x]);
		x++;
	}
	printf("\n");
	
	// ft_move_left(tab, tab_s, 0);
	//ft_move_right(tab, tab_s);
	//ft_move_up(tab, tab_s, 0);
	ft_move_down(tab, tab_s, 0);
	x = 0;
	while (x < tab_s)
	{
		if (x % 4 == 0)
			printf("\n");
		printf("%d", tab[x]);
		x++;
	}
	printf("\n");
	free(tab);
	return (0);
}
