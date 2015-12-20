/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:19:23 by lleverge          #+#    #+#             */
/*   Updated: 2015/12/20 17:05:21 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	remove_piece(t_matrix **matrix, char letter)
{
	int i;
	int j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == letter)
				matrix[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		valid_piece(int i, int j, t_matrix **matrix, char **piece)
{
	if (matrix[i][j] != '.' && piece[i][j] == '#')
		return (1);
	else
		return (0);
}

int		put_piece(t_matrix **matrix, int pos_x, int pos_y, t_tetri **piece)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (piece->tetri[i][j] == '#' && matrix[pos_x + i - piece->offsetx][pos_y + j - piece->offsetx] == '.' )
				matrix->draw[pos_x + i - piece->offsetx][pos_y + j - piece->offsetx] = piece->letter;
			else
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		solver(t_matrix **matrix, t_tetri piece)
{
	int i;
	int	j;
	int ret;

	i = 0;
	j = 0;
	while (i < matrix->height)
	{
		j = 0;
		while (j < matrix->width)
		{
			if (valid_piece(i, j, matrix->draw, piece->tetri) == 0)
			{
				put_piece(i, j, matrix->draw, piece->tetri);
				if (piece->next == NULL)
					return (0);
				else
					ret = put_piece(matrix, i, j, piece->next);
				if (ret == 1)
					remove_piece(matrix, piece->lettre);
				if (ret == 0)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
