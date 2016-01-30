/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartins <bmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 13:03:51 by bmartins          #+#    #+#             */
/*   Updated: 2014/11/17 14:01:25 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	len_str;
	char	*str;

	if (!s)
		return (NULL);
	len_str = ft_strlen(s);
	if (start > len_str || len > len_str)
		return (NULL);
	if (start + len > len_str)
		return (NULL);
	if (!(str = ft_strnew(len + 1)))
		return (NULL);
	str = ft_strncpy(str, s + start, len);
	str[len] = '\0';
	return (str);
}
