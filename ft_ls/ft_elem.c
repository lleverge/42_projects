/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 13:24:16 by lleverge          #+#    #+#             */
/*   Updated: 2016/02/10 13:36:52 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_elem		*info_in_list(t_elem *start, char *fname, char *path)
{
	t_stat		stat;
	t_elem		*tmp;
	t_elem		*voyager;

	tmp = (t_elem *)malloc(sizeof(t_elem));
	voyager = start;
	if (lstat(path, &stat) <= 0)
	{
		get_infos(fname, tmp, stat);
		if (getpwuid(stat.st_uid) != NULL)
			tmp->user = ft_strdup(getpwuid(stat.st_uid)->pw_name);
		else
			tmp->user = ft_strdup("");
		if (getgrgid(stat.st_gid) != NULL)
			tmp->group = ft_strdup(getgrgid(stat.st_gid)->gr_name);
		else
			tmp->group = ft_strdup("");
	}
	if (start == NULL)
		return (tmp);
	while (voyager->next)
		voyager = voyager->next;
	voyager->next = tmp;
	return (start);
}

void		ft_create_list(char *path)
{
	DIR				*ret;
	struct dirent	*elem;
	t_elem			*list;
	t_pad			*pad;

	pad = NULL;
    if ((ret = opendir(path)) == NULL)
	{
		ft_putstr("opendir error\n");
		return ;
	}
	elem = readdir(ret);
	if (!(list = (t_elem *)malloc(sizeof(t_elem))))
		exit(1);
	if (!(pad = (t_pad *)malloc(sizeof(t_pad))))
		exit(1);
	list = NULL;
	while (elem)
	{
		list = info_in_list(list, elem->d_name, ft_strjoin(path, elem->d_name));
		elem = readdir(ret);
	}
	list = ft_sort_ascii(list);
	ft_putstr("total ");
	ft_putnbr(count_blocks(list));
	ft_putchar('\n');
	ft_padding(&list, pad);
	while (list)
	{
		print_infos(list);
		ft_putchar('\n');
		list = list->next;
	}
	closedir(ret);
}

int			main(int argc, char **argv)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (++i < argc)
	{
		path = argv[i];
		ft_create_list(ft_strjoin(path, "/"));
	}
	if (!path)
		ft_create_list("./");
	return (0);
}
