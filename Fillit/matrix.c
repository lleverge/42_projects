/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 17:20:42 by lleverge          #+#    #+#             */
/*   Updated: 2015/12/21 15:57:03 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			*ft_newline(int	size)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (i < size)
	{
		str[i] = '.';
		i++;
	}
	str[i] = '\0';
	return (str);
}

t_matrix		init_matrix(int height, int width)
{
	t_matrix	matrix;
	int			i;

	i = 0;
	matrix.draw = (char **)malloc(sizeof(char *) * (height + 1));
	while (i < height)
	{
		matrix.draw[i] = ft_newline(width);
		i++;
	}
	matrix.draw[i] = 0;
	matrix.height = height;
	matrix.width = width;
	matrix.pos_x = 0;
	matrix.pos_y = 0;
	return (matrix);
}

t_matrix		increase_matrix(t_matrix matrix)
{
	t_matrix	new_matrix;

	new_matrix = init_matrix(matrix.height + 1, matrix.width + 1);
	return (new_matrix);
}

void	free_matrix(t_matrix *matrix)
{
	int	i;

	i = 0;
	while (matrix->draw[i] != 0)
	{
		ft_strdel(&(matrix->draw[i]));
		i++;
	}
	matrix->draw = NULL;
}
