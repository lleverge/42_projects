/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 13:26:04 by lleverge          #+#    #+#             */
/*   Updated: 2016/01/29 13:46:28 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_list_dir(char *name)
{
	DIR				*ds;
	int				len;
	struct dirent	*dp;

	ds = opendir(name);
	if (ds == NULL)
	{
		ft_putstr("opendirerror\n");
		return (-1);
	}
	len = ft_strlen(name);
	while ((dp = readdir(ds)) != NULL)
	{
		if (dp->d_name[0] != '.')
		{
			ft_putstr(dp->d_name);
			ft_putchar('\n');
		}
	}
	(void)closedir(ds);
	return (0);
}

int				main(int argc, char **argv)
{
	if (argc == 2)
		ft_list_dir(argv[1]);
	ft_putchar('\n');
	return (0);
}
