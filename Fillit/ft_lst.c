/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 10:46:18 by lleverge          #+#    #+#             */
/*   Updated: 2015/12/21 17:39:39 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			count_height(char **piece)
{
	int	count;
	int	i;
	int	j;
	int flag;

	count = 0;
	i = 0;
	flag = 0;
	while (piece[i] != 0)
	{
		j = 0;
		while (piece[i][j])
		{
			if (piece[i][j] == '#' && i == 0 && flag == 0)
			{
				count++;
				flag = 1;
			}
			if ( i > 0 && piece[i][j] == '#' && piece[i - 1][j] == '#' && flag == 0)
			{
				flag = 1;
				count++;
			}
			j++;
		}
		flag = 0;
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
	count_max = 0;
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
	int offsetx;

	i = 0;
	offsetx = 42;
	while (i < 4)
	{
		while (j < 4)
		{
			if (piece[i][j] == '#' && j < offsetx)
				offsetx = j;
			j++;
		}
		j = 0;
		i++;
	}
	return (offsetx);
}

int			count_offsety(char **piece)
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
				return (i);
			j++;
		}
		i++;
	}
	return (-42);
}

t_tetri		*tetri_lstnew(char **piece, char let)
{
  t_tetri	*new;

  new = (t_tetri *)malloc(sizeof(t_tetri));
  if (!new)
    return (NULL);
  else
    {
      new->tetri = piece;
      new->letter = let;
      new->width = count_width(piece);
      new->height = count_height(piece);
      new->offsetx = count_offsetx(piece);
      new->offsety = count_offsety(piece);
      new->next = NULL;
    }
  return (new);
}
