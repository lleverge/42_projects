/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 13:26:04 by lleverge          #+#    #+#             */
/*   Updated: 2016/02/16 11:59:32 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_rec_list_dir(char *name);

static void		ft_display_path(char *d_name)
{
	if (d_name[0] != '.')
	{
		ft_putstr(d_name);
		ft_putchar('\n');
	}
}

static void		ft_display_dirname(char *name)
{
	ft_putchar('\n');
	ft_putstr(name);
	ft_putstr(":\n");
}

static void		ft_new_path(char *name, char *d_name)
{
	char *path_name;

	path_name = ft_strjoin(name, "/");
	path_name = ft_strjoin(path_name, d_name);
	ft_rec_list_dir(path_name);
}

int				ft_rec_list_dir(char *name)
{
	DIR					*ds;
	struct dirent		*dp;
	char				*d_name;

	ds = opendir(name);
	if (ds == NULL)
		return (-1);
	ft_display_dirname(name);
	while (1)
	{
		dp = readdir(ds);
		if (!dp)
			return (0);
		d_name = dp->d_name;
		ft_display_path(dp->d_name);
		if (dp->d_type & DT_DIR)
		{
			if (ft_strcmp(d_name, ".") != 0 && ft_strcmp(d_name, "..") != 0
				&& dp->d_name[0] != '.')
				ft_new_path(name, d_name);
		}
	}
	if (closedir(ds) == -1)
		return (-1);
	return (0);
}

int				main(int argc, char **argv)
{
	if (argc == 2)
		ft_rec_list_dir(argv[1]);
	ft_putchar('\n');
	return (0);
}
