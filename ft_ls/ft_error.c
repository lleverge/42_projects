/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:48:18 by lleverge          #+#    #+#             */
/*   Updated: 2016/03/11 13:22:38 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		opt_error(char *s)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putendl_fd(s, 2);
	ft_putstr_fd("usage: ft_ls [-Ralrt] [file ...]\n", 2);
	exit(1);
}

void		no_file_dir(char *fname)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_putstr("ft_ls: ");
	while (fname[i])
		i++;
	while (j < i - 1)
	{
		ft_putchar(fname[j]);
		j++;
	}
	perror(" ");
	exit(1);
}
