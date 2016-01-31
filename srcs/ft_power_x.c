/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:21:03 by amerelo           #+#    #+#             */
/*   Updated: 2016/01/30 13:21:07 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int			ft_power_x(int x)
{
	int y;
	int tmp;

	y = x;
	tmp = 1;
	while (tmp < y)
	{
		x += y;
		tmp++;
	}
	return (x);
}