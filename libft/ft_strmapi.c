/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartins <bmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 13:01:56 by bmartins          #+#    #+#             */
/*   Updated: 2014/11/14 15:44:35 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		str[i] = f(i, ptr[i]);
		i++;
	}
	return (str);
}
