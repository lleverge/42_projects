/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:06:47 by lleverge          #+#    #+#             */
/*   Updated: 2015/12/15 14:12:10 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/libft.h"
#include <fcntl.h>
#include "fillit.h"

char		*ft_cattetri(char **tab, int start_index, int end_index)
{
	char *piece;

	piece = (char *)malloc(sizeof(char) * 17);
	while (start_index <= end_index)
	{
		ft_strcat(piece, tab[start_index]);
		start_index++;
	}
	return (piece);
}

char		**pieces_tab(char *file_name)
{
	char	buf[546];
	int		fd;
	int		ret;
	char	**tab;
	int		i;

	i = 0;
	buf[545] = '\0';
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
	t_tetri *list;

	i = 0;
	tab = pieces_tab(argv[1]);
	list = tetri_lstnew(ft_cattetri(tab, 8, 11), 'A');
	ft_putstr(list->tetri);
	ft_putchar('\n');
	ft_putnbr(list->width);
	ft_putchar('\n');
	ft_putnbr(list->height);
	ft_putchar('\n');
	ft_putchar(list->letter);
	ft_putchar('\n');
	ft_putnbr(list->offsety);
	ft_putchar('\n');
	ft_putnbr(list->offsetx);
	return (0);
}
