/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:06:47 by lleverge          #+#    #+#             */
/*   Updated: 2015/12/15 15:38:48 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/libft.h"
#include <fcntl.h>
#include "fillit.h"

char		*ft_cattetri(char **tab, int start_index, int end_index)
{
	char *piece;

	piece = (char *)malloc(sizeof(char) * 17);
	while (start_index <= end_index && tab[start_index])
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
	int		piece_nbr;
	char	c;
	t_tetri *list;
	t_tetri *listtmp;

	i = 0;
	c = 97;
	piece_nbr = 7;
	tab = pieces_tab(argv[1]);
	list = tetri_lstnew(ft_cattetri(tab, i, i + 3), c);
	listtmp = list;
	while (piece_nbr--)
	{
		i += 4;
		list->next = tetri_lstnew(ft_cattetri(tab, i, i + 3), c);
		list = list->next;
	}
	while (listtmp->next)
	{
		ft_putstr("tetri: ");
		ft_putstr(listtmp->tetri);
		ft_putchar('\n');
		ft_putstr("hauteur: ");
		ft_putnbr(listtmp->height);
		ft_putchar('\n');
		ft_putstr("largeur: ");
		ft_putnbr(listtmp->width);
		ft_putchar('\n');
		ft_putstr("offsetx: ");
		ft_putnbr(listtmp->offsetx);
		ft_putchar('\n');
		ft_putstr("offsety: ");
		ft_putnbr(listtmp->offsety);
		ft_putchar('\n');
		ft_putstr("letter: ");
		ft_putchar(listtmp->letter);
		ft_putchar('\n');
		listtmp = listtmp->next;
	}
	return (0);
}
