/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:06:47 by lleverge          #+#    #+#             */
/*   Updated: 2015/12/15 10:55:02 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/libft.h"
#include <fcntl.h>
#include "fillit.h"

char		**pieces_tab(char *file_name)
{
	char	buf[545];
	int		fd;
	int		ret;
	char	**tab;
	int		i;

	i = 0;
	buf[5] = '\0';
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open error \n");
		return (NULL);
	}
	ret = read(fd, buf, 545);
	tab = ft_strsplit(buf, '\n');
	return (tab);
}

int		main(int argc, char ** argv)
{
	char	**tab;
	int		i;

	i = 0;
	tab = pieces_tab(argv[1]);
	ft_putstr(ft_cattetri(tab, 0, 3));
	return (0);
}
