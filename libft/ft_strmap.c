/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartins <bmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 12:55:11 by bmartins          #+#    #+#             */
/*   Updated: 2014/11/16 16:48:52 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*ptr;
	char	*str;

	i = 0;
	if (!(*f) || !s)
		return (NULL);
	ptr = (char *)s;
	str = ft_strnew(ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	while (ptr[i])
	{
		str[i] = f(ptr[i]);
		i++;
	}
	return (str);
}
