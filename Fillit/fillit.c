/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:06:47 by lleverge          #+#    #+#             */
/*   Updated: 2015/12/21 18:35:57 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void    free_list(t_tetri *list)
{
    int     i;
    t_tetri *tmp;

    i = 0;
    while (list != NULL)
    {
        tmp = list;
        list = list->next;
        free_tab(tmp->tetri);
        tmp->tetri = NULL;
        free(tmp);
    }
    free(list);
}

char		**ft_split_tetri(char **tab, int start, int end)
{
	char	**piece;
	int		i;

	i = 0;
	piece = (char **)malloc(sizeof(char *) * 5);
	while (start <= end && tab[start])
	{
		piece[i] = ft_strdup(tab[start]);
		start++;
		i++;
	}
	piece[i] = 0;
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
	int j = 0;

	i = 0;
	c = 65;
	list = NULL;
	list = tetri_lstnew(ft_split_tetri(tab, i, i + 3), c);
	listtmp = list;
	piece_nbr--;
	while (piece_nbr--)
	{
	  i += 4;
	  c += 1;
	  j = 0;
	  ft_putstr("lal\n");
	  tetri_lstnew(ft_split_tetri(tab, i, i + 3), c);
	  list = list->next;
	}
	return (listtmp);
}

void		print_matrix(t_matrix matrix)
{
	int i;

	i = 0;
	while (matrix.draw[i])
	{
		ft_putstr(matrix.draw[i]);
		ft_putchar('\n');
		i++;
	}
}

int			main(int ac, char **av)
{
	int			piece_nbr;
	char		**tab;
	t_tetri		*list;
	t_matrix	matrix;
	int			i = 0;

	if (ac != 2)
		ft_error();
	else if (ft_check_file(ft_read_file(av[1])) == 1)
	{
		piece_nbr = ft_count_tetri(ft_read_file(av[1]));
		ft_putstr("\n-------OK--------\n");
		printf("Nb tetri : %d\n\n", piece_nbr);
		tab = pieces_intab(av[1]);
		list = piece_inlist(piece_nbr, tab);
		free_tab(tab);
		matrix = init_matrix(piece_nbr, piece_nbr);
		while (solver(matrix, list) == 1)
		{
			while (matrix.draw[i])
				i++;
			printf("i is %d\n", i);
			matrix = increase_matrix(matrix);
		}
		free_list(list);
		free_matrix(&matrix);
	}
	else
		ft_putstr("FORMAT ERROR\n");
	return (0);
}
