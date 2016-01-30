/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartins <bmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:34:00 by bmartins          #+#    #+#             */
/*   Updated: 2014/11/16 13:51:06 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*s2;

	if (!s1)
		return (NULL);
	s2 = ft_strnew(ft_strlen(s1) + 1);
	if (s2 == NULL)
		return (NULL);
	ft_strncpy(s2, s1, ft_strlen(s1));
	return (s2);
}
