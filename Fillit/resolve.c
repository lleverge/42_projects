/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:19:23 by lleverge          #+#    #+#             */
/*   Updated: 2015/12/21 17:06:05 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int		valid_piece(int i, int j, t_matrix matrix, t_tetri *list)
{
	if (matrix.draw[i][j] == '.' && list->tetri[i + list->offsety][j + list->offsetx] == '#')
		return (0);
	else
		return (1);
}

int		put_piece(t_matrix matrix, t_tetri *list)
{
	int i;
	int j;

	i = 0;
	while (i < matrix.height)
	{
		j = 0;
		while (j < matrix.width)
		{
			if (valid_piece(i, j, matrix, list) == 0)
				matrix.draw[i][j] = list->letter;
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
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (valid_piece(i, j, matrix, list) == 0)
				put_piece(matrix, list);
			else
			{
				remove_piece(matrix, list->letter);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}


/*
int		put_piece(t_matrix matrix, int pos_x, int pos_y, t_tetri *list)
{
	int	i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (list->tetri[i][j] == '#' && matrix.draw[i][j] == '.')
				matrix.draw[i][j] = list->letter;
			else
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		solver(t_matrix matrix, t_tetri *list)
{
	int i;
	int	j;
	int ret;

	i = 0;
	j = 0;
	while (i < matrix.height)
	{
		j = 0;
		while (j < matrix.width)
		{
			if (valid_piece(i, j, matrix, list->tetri) == 0)
			{
				put_piece(matrix, i, j, list);
				if (list->next == NULL)
					return (0);
				else
					ret = put_piece(matrix, i, j, list->next);
				if (ret == 1)
					remove_piece(matrix, list->letter);
				if (ret == 0)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
	} */
