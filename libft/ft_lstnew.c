/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartins <bmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 16:59:51 by bmartins          #+#    #+#             */
/*   Updated: 2015/01/03 13:12:51 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_elem;

	new_elem = (t_list*)malloc(sizeof(t_list));
	if (new_elem == NULL)
		return (NULL);
	if (!content || !content_size)
	{
		new_elem->content = NULL;
		new_elem->content_size = 0;
	}
	else
	{
		if (!(new_elem->content = (void *)malloc(sizeof(content))))
			return (NULL);
		if (content_size >= 4294967295)
			return (NULL);
		if (!(ft_memcpy(new_elem->content, content, content_size + 1)))
			return (NULL);
		new_elem->content_size = content_size;
	}
	new_elem->next = NULL;
	return (new_elem);
}
