/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 10:46:18 by lleverge          #+#    #+#             */
/*   Updated: 2015/12/18 17:37:55 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/libft.h"
#include "fillit.h"

int			count_height(char **piece)
{
	int	count;
	int	i;
	int	j;

	count = 1;
	i = 1;
	while (piece[i])
	{
		j = 0;
		while (piece[i][j])
		{
			if (piece[i][j] == '#' && piece[i - 1][j] == '#')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int			count_width(char **piece)
{
	int	i;
	int	j;
	int	count;
	int	count_max;

	i = 0;
	count = 0;
	count_max = 42;
	while (piece[i])
	{
		j = 0;
		count = 0;
		while (piece[i][j])
		{
			if (piece[i][j] == '#')
				count++;
			j++;
		}
		if (count > count_max)
			count_max = count;
		i++;
	}
	return (count_max);
}

int			count_offsetx(char **piece)
{
	int	i;
	int	j;

	i = 0;
	while (piece[i])
	{
		j = 0;
		while (piece[i][j])
		{
			if (piece[i][j] == '#')
				return (j);
			j++;
		}
		i++;
	}
	return (-42);
}

int			count_offsety(char **piece)
{
	int	i;
	int	j;

	while (piece[i])
	{
		j = 0;
		while (piece[i][j])
		{
			if (piece[i][j] == '#')
				return (i);
			j++;
		}
		i++;
	}
	return (-42);
}

t_tetri		*tetri_lstnew(char **piece, char let)
{
	t_tetri	*list;

	list = (t_tetri *)malloc(sizeof(t_tetri));
	if (!list)
		return (NULL);
	else
	{
		list->tetri = piece;
		list->letter = let;
		list->width = count_width(piece);
		list->height = count_height(piece);
		list->offsetx = count_offsetx(piece);
		list->offsety = count_offsety(piece);
		list->next = NULL;
	}
	return (list);
}
