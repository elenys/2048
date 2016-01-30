/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartins <bmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:34:27 by bmartins          #+#    #+#             */
/*   Updated: 2014/11/17 17:08:55 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	i = ft_strlen(dest);
	while (src[j] && ((size_t)j < n))
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}
