/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 13:24:16 by lleverge          #+#    #+#             */
/*   Updated: 2016/02/16 14:27:05 by lleverge         ###   ########.fr       */
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

void		ft_display(t_elem *list, t_opt *options, t_pad *pad)
{
	if (options->l == 1)
		ft_display_l(list, count_blocks(list), pad);
	else
		return ;
}

void		ft_create_list(char *path, t_opt *options)
{
	DIR				*ret;
	struct dirent	*elem;
	t_elem			*list;
	t_pad			*pad;

	pad = NULL;
	if ((ret = opendir(path)) == NULL)
		no_file_dir(path);
	elem = readdir(ret);
	if (!(list = (t_elem *)malloc(sizeof(t_elem))) ||
		(!(pad = (t_pad *)malloc(sizeof(t_pad)))))
		exit(1);
	list = NULL;
	while (elem)
	{
		list = info_in_list(list, elem->d_name, ft_strjoin(path, elem->d_name));
		elem = readdir(ret);
	}
	list = ft_sort_ascii(list);
	ft_display(list, options, pad);
	closedir(ret);
}

int			main(int argc, char **argv)
{
	int		i;
	char	*path;
	t_opt	*options;

	i = 1;
	path = NULL;
	options = NULL;
	if (!(options = (t_opt *)malloc(sizeof(t_opt))))
		return (-1);
	init_opt(options);
	ft_detect_opt(argv, argc, options);
	while (++i < argc)
	{
		path = argv[i];
		ft_create_list(ft_strjoin(path, "/"), options);
	}
	if (!path)
	  ft_create_list("./", options);
	return (0);
}
