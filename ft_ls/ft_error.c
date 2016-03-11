/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:48:18 by lleverge          #+#    #+#             */
/*   Updated: 2016/03/11 15:26:37 by lleverge         ###   ########.fr       */
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

char		*remove_slash(char *name)
{
	if (name[(ft_strlen(name) - 1)] == '/')
		name[(ft_strlen(name) - 1)] = '\0';
	return (name);
}

void		no_file_dir(char *fname)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_putstr("ft_ls: ");
	perror(remove_slash(fname));
	exit(1);
}
