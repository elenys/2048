/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartins <bmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 12:27:22 by bmartins          #+#    #+#             */
/*   Updated: 2014/11/17 17:07:16 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL || s[0] == '\0')
		ft_putstr_fd("(NULL)", fd);
	else
	{
		while (s[i] != '\0')
			ft_putchar_fd(s[i++], fd);
	}
}
