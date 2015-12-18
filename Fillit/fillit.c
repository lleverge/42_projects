/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:06:47 by lleverge          #+#    #+#             */
/*   Updated: 2015/12/18 17:41:10 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_split_tetri(char **tab, int start, int end)
{
	char **piece;

	piece = (char **)malloc(sizeof(char *) * 5);
	while (start <= end && tab[start])
	{
		piece[start] = ft_strdup(tab[start]);
		start++;
	}
	piece[start] = NULL;
	return (piece);
}

char		**pieces_intab(char *file_name)
{
	char	buf[BUF_SIZE];
	int		fd;
	int		ret;
	char	**tab;
	int		i;

	i = 0;
	buf[545] = '\0';
	ft_bzero(buf, BUF_SIZE);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open error \n");
		return (NULL);
	}
	ret = read(fd, buf, BUF_SIZE);
	tab = ft_strsplit(buf, '\n');
	close(fd);
	return (tab);
}

t_tetri		*piece_inlist(int piece_nbr, char **tab)
{
	int		i;
	char	c;
	t_tetri	*list;
	t_tetri	*listtmp;

	i = 0;
	c = 65;
	list = tetri_lstnew(ft_split_tetri(tab, i, i + 3), c);
	listtmp = list;
	while (piece_nbr--)
	{
		i += 4;
		c += 1;
		list->next = tetri_lstnew(ft_split_tetri(tab, i, i + 3), c);
		list = list->next;
	}
	return (listtmp);
}

int			main(int ac, char **av)
{
	int		piece_nbr;
	char	**tab;
	t_tetri *list;
	int		i;
	int		j;

	if (ac != 2)
		ft_error();
	else if (ft_check_file(ft_read_file(av[1])) == 1)
	{
		piece_nbr = ft_count_tetri(ft_read_file(av[1]));
		ft_putstr("\n-------OK--------\n");
		printf("Nb tetri : %d\n\n", piece_nbr);
		tab = pieces_intab(av[1]);
		list = piece_inlist(piece_nbr, tab);
		while (list->next)
		{
			while (list->tetri[i])
			{
				j = 0;
				while (list->tetri[i][j])
				{
					ft_putchar(list->tetri[i][j]);
					j++;
				}
				ft_putchar('\n');
				i++;
			}
			ft_putstr("hauteur: ");
			ft_putnbr(list->height);
			ft_putchar('\n');
			ft_putstr("largeur: ");			
			ft_putnbr(list->width);
			ft_putchar('\n');
			ft_putstr("offsetx: ");
			ft_putnbr(list->offsetx);
			ft_putchar('\n');
			ft_putstr("offsety: ");
			ft_putnbr(list->offsety);
			ft_putchar('\n');
			list = list->next;
		}
	}
	else
		ft_putstr("FORMAT ERROR\n");
	return (0);
}
