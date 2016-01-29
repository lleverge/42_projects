/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 13:50:18 by lleverge          #+#    #+#             */
/*   Updated: 2016/01/29 14:27:49 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <pwd.h>

int		ft_inspect_file(void)
{
	DIR				*ds;
	struct dirent	*dp;
	struct stat     statbuf;
	struct passwd	*pwd;

	ds = opendir(".");
	if (ds == NULL)
	{
		ft_putstr("opendirerror\n");
		return (-1);
	}
	while ((dp = readdir(ds)) != NULL)
	{
		if ((pwd = getpwuid(statbuf.st_uid)) != NULL)
		{
			ft_putstr("pw_name: ");
			ft_putstr(pwd->pw_name);
			ft_putstr(" , pw_class: ");
			ft_putstr(pwd->pw_class);
			ft_putstr(" , pw_dir: ");
			ft_putstr(pwd->pw_dir);
			ft_putchar('\n');
		}
	}
	(void)closedir(ds);
	return (0);
}

int		main(void)
{
	ft_inspect_file();
	ft_putchar('\n');
	return (0);
}
