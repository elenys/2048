/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartins <bmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 12:03:28 by bmartins          #+#    #+#             */
/*   Updated: 2015/01/03 14:39:24 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_elem;
	t_list	*start;

	if (!f || !lst)
		return (NULL);
	start = NULL;
	while (lst)
	{
		new_elem = ft_lstnew(f(lst)->content, f(lst)->content_size);
		if (new_elem == NULL)
			return (NULL);
		if (start == NULL)
			start = new_elem;
		else
			ft_lstadd_end(&start, new_elem);
		lst = lst->next;
	}
	return (start);
}
