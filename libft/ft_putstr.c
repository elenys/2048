/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartins <bmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:33:32 by bmartins          #+#    #+#             */
/*   Updated: 2014/11/17 17:07:09 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		ft_putstr("(NULL)");
	else if (s[0] == '\0')
		ft_putstr("NULL");
	else
	{
		while (s[i] != '\0')
			ft_putchar(s[i++]);
	}
}
