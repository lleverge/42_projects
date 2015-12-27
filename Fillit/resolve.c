/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:19:23 by lleverge          #+#    #+#             */
/*   Updated: 2015/12/27 15:31:38 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	remove_piece(t_matrix matrix, char letter)
{
	int i;
	int j;

	i = 0;
	while (matrix.draw[i])
	{
		j = 0;
		while (matrix.draw[i][j])
		{
			if (matrix.draw[i][j] == letter)
				matrix.draw[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		valid_piece(int l, int c, t_matrix matrix, t_tetri *list)
{
	int		i;
	int		j;

	if (l + list->height > matrix.height)
		return (1);
	if (c + list->width > matrix.width)
		return (1);
	i = list->offsety;
	while (i < 4)
	{
		j = list->offsetx;
		while (j < 4)
		{
			if (list->tetri[i][j] == '#' && matrix.draw[c + i - list->offsety][l + j - list->offsetx] != '.')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		put_piece(t_matrix matrix, t_tetri *list, int l, int c)
{
	int i;
	int j;

	i = list->offsety;
	while (i <= list->height)
	{
		j = list->offsetx;
		while (j <= list->width)
		{
			if (list->tetri[i][j] == '#')
				matrix.draw[c + i - list->offsety][l + j - list->offsetx] = list->letter;
			j++;
		}
		i++;
	}
	print_matrix(matrix);
	ft_putchar('\n');
	return (0);
}

int		solver(t_matrix matrix, t_tetri *list)
{
	int i;
	int j;

	i = 0;
	while (matrix.draw[i])
	{
		j = 0;
		while (matrix.draw[i][j])
		{
			if (valid_piece(i, j, matrix, list) == 0)
			{
				printf("Putting piece %c\n", list->letter);
				put_piece(matrix, list, i, j);
				if (!list->next)
					return (0);
				if (solver(matrix, list->next) == 0)
					return (0);
				else
					remove_piece(matrix, list->letter);
			}
			j++;
		}
		i++;
	}
	return (1);
}
