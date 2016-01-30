/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartins <bmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 11:15:11 by bmartins          #+#    #+#             */
/*   Updated: 2015/12/08 10:29:37 by bmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_set_line(char **nline, char **save, int rv)
{
	int			i;

	i = 0;
	while ((*nline)[i] != '\n')
		i++;
	ft_strclr(*save);
	*save = ft_strdup(ft_strsub(*nline, (i + 1), (ft_strlen(*nline) - i - 1)));
	if (*save == NULL)
		return (-1);
	*nline = ft_strdup(ft_strsub(*nline, 0, i));
	if (*nline == NULL)
		return (-1);
	if (!(*save)[0] && (i && BUFF_SIZE != 1) && rv != BUFF_SIZE && rv != 1)
		return (0);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	char		*buf;
	char		*nline;
	ssize_t		rv;
	static char *save = NULL;

	if (fd < 0 || !line || BUFF_SIZE <= 0 || !(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	nline = save ? ft_strdup(save) : ft_strnew(0);
	rv = nline ? 1 : -1;
	while (!ft_strchr(nline, '\n') && rv > 0)
	{
		rv = read(fd, buf, BUFF_SIZE);
		if (rv > 0)
			nline = ft_strjoin(nline, buf);
		rv = nline ? rv : -1;
		ft_strclr(buf);
	}
	ft_strdel(&buf);
	if (rv > 0)
		rv = ft_set_line(&nline, &save, rv);
	if (rv == 0)
		ft_strdel(&save);
	*line = nline;
	return (rv);
}
