/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winv_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:21:03 by amerelo           #+#    #+#             */
/*   Updated: 2016/01/31 19:33:36 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int				winv_valid(t_env *env)
{
	int a;
	int b;

	a = WIN_VALUE;
	if (a == 2 && env->cont != 1)
		return (1);
	while (a > 2)
	{
		b = a % 2;
		a = a / 2;
		if (b != 0)
			return (0);
		if (a == 2)
			return (1);
	}
	return (0);
}
