/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartins <bmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:51:45 by bmartins          #+#    #+#             */
/*   Updated: 2015/01/03 11:35:25 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		len;
	int		i;
	char	*s1;

	i = 0;
	if (!s)
		return (NULL);
	while (ft_isspace(*s) && *s)
		s++;
	len = ft_strlen(s);
	while (s[i])
		i++;
	i--;
	while (ft_isspace(s[i]) && i >= 0 && *s)
	{
		len--;
		i--;
	}
	if (!(s1 = ft_strnew(len + 1)))
		return (NULL);
	ft_strncpy(s1, s, (len));
	s1[len + i] = '\0';
	return (s1);
}
