/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fviolin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 09:26:28 by fviolin           #+#    #+#             */
/*   Updated: 2016/01/05 12:48:39 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		ft_check_grid(char *s)
{
	int i;
	int	nb_char;
	int	nb_line;
	int	nb_tetri;

	i = -1;
	nb_char = 0;
	nb_line = 0;
	nb_tetri = 0;
	while (s[++i])
	{
		if (s[i] == '.' || s[i] == '#')
			nb_char++;
		if ((nb_char % 4 == 0) && s[i] == '\n' && s[i - 1] != '\n')
			nb_line++;
		if ((nb_line % 4 == 0) && s[i] == '\n' && s[i - 1] == '\n')
			nb_tetri++;
	}
	if (!s[i] && (nb_char % 16 == 0) && (nb_line % 4 == 0))
		nb_tetri++;
	if ((ft_count_char(s, '#') == nb_tetri * 4) &&
		(ft_count_char(s, '.') == nb_tetri * 12)
		&& (ft_count_char(s, '\n') == nb_line + nb_tetri - 1))
		return (1);
	return (0);
}

static	int		ft_check_tetri(char *s)
{
	int count;

	count = 0;
	while (*s)
	{
		if (*s == '#')
		{
			count++;
			if (count % 4 != 0 && *(s + 4) != '#' && *(s + 1) != '#'
					&& *(s + 5) != '#')
				return (0);
			if (count % 4 == 0 && *(s - 1) != '#' && *(s + 1) != '#'
					&& *(s - 5) != '#')
				return (0);
		}
		s++;
	}
	return (1);
}

static	int		ft_print_error_tetri(char *s)
{
	if (ft_check_tetri(s) == 0)
	{
		free(s);
		return (0);
	}
	else
	{
		free(s);
		return (1);
	}
}

static	int		ft_check_newline(char *s)
{
	int char_nbr;
	int line_nbr;
	int i;

	i = 0;
	char_nbr = 0;
	line_nbr = 0;
	while (s[i])
	{
		if (s[i] == '.' || s[i] == '#')
			char_nbr++;
		if ((char_nbr % 4 == 0) && s[i] == '\n' && s[i - 1] != '\n')
			line_nbr++;
		if (s[i] != '\n' && s[i - 1] != '\n' && line_nbr % 5 == 0)
			return (1);
		i++;
	}
	return (0);
}

int				ft_check_file(char *s)
{
	if (s)
	{
		if (ft_check_grid(s) == 1 && ft_print_error_tetri(s) == 1
			&& ft_check_newline(s) == 1)
			return (1);
	}
	return (0);
}
