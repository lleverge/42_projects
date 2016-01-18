/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 11:11:41 by lleverge          #+#    #+#             */
/*   Updated: 2016/01/18 11:16:38 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char			*str_concat(char *str, char *buff)
{
	char *temp;

	temp = ft_strjoin(str, buff);
	ft_strdel(&str);
	return (temp);
}

static int			get_line(char **line, char *buff, char *overflow)
{
	char *temp;

	if ((temp = ft_strchr(buff, '\n')))
	{
		*temp = '\0';
		*line = ft_strdup(buff);
		ft_memmove(overflow, temp + 1, ft_strlen(temp + 1) + 1);
		return (1);
	}
	return (0);
}

int					get_next_line(int const fd, char **line)
{
	static char overflow[255][BUFF_SIZE + 1];
	char		buffer[BUFF_SIZE + 1];
	char		*str;
	int			ret;

	if (fd < 0)
		return (-1);
	if (get_line(line, overflow[fd], overflow[fd]) == 1)
		return (1);
	str = ft_strdup(overflow[fd]);
	ft_bzero(buffer, BUFF_SIZE + 1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) != 0)
	{
		if (ret == -1)
			return (-1);
		buffer[ret] = '\0';
		str = str_concat(str, buffer);
		if (get_line(line, str, overflow[fd]) == 1)
		{
			ft_strdel(&str);
			return (1);
		}
	}
	*line = str;
	return (0);
}
