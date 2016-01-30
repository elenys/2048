/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartins <bmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 17:12:31 by bmartins          #+#    #+#             */
/*   Updated: 2014/11/17 17:06:14 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr_src;
	char	*ptr_dst;

	ptr_src = (char *)src;
	ptr_dst = (char *)dst;
	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	ptr_dst += len;
	ptr_src += len;
	while (len)
	{
		*--ptr_dst = *--ptr_src;
		len--;
	}
	return (dst);
}
