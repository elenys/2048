/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartins <bmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 16:38:31 by bmartins          #+#    #+#             */
/*   Updated: 2014/11/17 17:08:16 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*strc;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	strc = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (strc == NULL)
		return (NULL);
	ft_strcat(strc, s1);
	ft_strcat((strc + ft_strlen(s1)), s2);
	return (strc);
}
