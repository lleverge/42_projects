/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 10:46:18 by lleverge          #+#    #+#             */
/*   Updated: 2015/12/15 11:57:57 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/libft.h"
#include "fillit.h"

char	*ft_cattetri(char **tab, int start_index, int end_index)
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

int		count_height(char *piece)
{
	int	count;
	int	i;
	int flag;

	count = 0;
	i = 0;
	flag = 0;
	while (piece[i])
	{
		if (i == 4 || i == 8 || i == 12)
			flag = 0;
		if(flag == 0 && piece[i] == '#')
		{
			count++;
			flag = 1;
		}
		i++;
	}
	return (count);
}

int		count_width(char *piece)
{
	int	count;
	int	count_max;
	int	i;
	int	flag;

	count = 0;
	i = 0;
	flag = 0;
	count_max = 0;
	while (piece[i])
	{
		if (i == 4 || i == 8 || i == 12)
			count = 0;
		while (piece[i] == '#')
		{
			count++;
			if (count > count_max)
				count_max = count;
		}
		i++;
	}
	return (count_max);
}

t_tetri		*ft_lstnew(char *piece, char let)
{
	t_tetri	*list;

	tetri = (t_tetri *)malloc(sizeof(t_tetri));
	if (!tetri)
		return (NULL);
	else
	{
		tetri->tetri = piece;
		tetri->letter = let;
		tetri->width = count_width(piece);
		tetri->height = count_height(piece);
		tetri->offsetx = count_offsetx(piece);
		tetri->offsety = count_offsety(piece);
		tetri->next = NULL;
	}
	return (list);
}
