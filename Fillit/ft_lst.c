/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 10:46:18 by lleverge          #+#    #+#             */
/*   Updated: 2015/12/15 16:10:31 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/libft.h"
#include "fillit.h"

int			count_height(char *piece)
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
		if (flag == 0 && piece[i] == '#')
		{
			count++;
			flag = 1;
		}
		i++;
	}
	return (count);
}

int			count_width(char *piece)
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
		if (piece[i] == '#')
			count++;
		if (count > count_max)
			count_max = count;
		i++;
	}
	return (count_max);
}

int			count_offsetx(char *piece)
{
	int	i;
	int	count;
	int	offsetx;

	i = 0;
	count = 0;
	offsetx = 42;
	while (piece[i])
	{
		if (i == 4 || i == 8 || i == 12)
			count = 0;
		if (count < offsetx && piece[i] == '#')
			offsetx = count;
		count++;
		i++;
	}
	return (offsetx);
}

int			count_offsety(char *piece)
{
	int	i;
	int flag;
	int	offsety;

	i = 0;
	flag = 0;
	while (piece[i])
	{
		if (i < 4 && piece[i] == '#')
		{
			offsety = 0;
			flag = 1;
		}
		if (i >= 4 && i < 8 && flag == 0 && piece[i] == '#')
		{
			offsety = 1;
			flag = 1;
		}
		if (i >= 8 && i < 12 && flag == 0 && piece[i] == '#')
		{
			offsety = 2;
			flag = 1;
		}
		if (i >= 12 && flag == 0 && piece[i] == '#')
			offsety = 3;
		i++;
	}
	return (offsety);
}

t_tetri		*tetri_lstnew(char *piece, char let)
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
