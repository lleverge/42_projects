/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 18:07:03 by lleverge          #+#    #+#             */
/*   Updated: 2016/02/10 10:26:58 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		get_infos(char *fname, t_elem *tmp, t_stat stat)
{
	tmp->name = ft_strdup(fname);
	tmp->modif_last = (long long)stat.st_mtime;
	tmp->create = stat.st_mtime;
	tmp->blocks = stat.st_blocks;
	tmp->perm = ft_perm(&stat);
	tmp->links = stat.st_nlink;
	tmp->is_dir = (tmp->perm[0] == 'd' && REAL_DIR(tmp->name));
	tmp->size = stat.st_size;
	tmp->next = NULL;
}

char		*ft_rights(char *perm, int i, t_stat *stat)
{
	perm[++i] = (stat->st_mode & S_IRUSR) ? 'r' : '-';
	perm[++i] = (stat->st_mode & S_IWUSR) ? 'w' : '-';
	perm[++i] = (stat->st_mode & S_IXUSR) ? 'x' : '-';
	perm[++i] = (stat->st_mode & S_IRGRP) ? 'r' : '-';
	perm[++i] = (stat->st_mode & S_IWGRP) ? 'w' : '-';
	perm[++i] = (stat->st_mode & S_IXGRP) ? 'x' : '-';
	perm[++i] = (stat->st_mode & S_IROTH) ? 'r' : '-';
	perm[++i] = (stat->st_mode & S_IWOTH) ? 'w' : '-';
	perm[++i] = (stat->st_mode & S_IXOTH) ? 'x' : '-';
	return (perm);
}

char		*ft_perm(t_stat *stat)
{
	char	perm[11];
	int		i;

	perm[10] = '\0';
	i = -1;
	if (S_ISDIR(stat->st_mode))
		perm[++i] = 'd';
	else if (S_ISBLK(stat->st_mode))
		perm[++i] = 'b';
	else if (S_ISCHR(stat->st_mode))
		perm[++i] = 'c';
	else if (S_ISLNK(stat->st_mode))
		perm[++i] = 'l';
	else if (S_ISFIFO(stat->st_mode))
		perm[++i] = 'p';
	else if (S_ISSOCK(stat->st_mode))
		perm[++i] = 's';
	else
		perm[++i] = '-';
	return (ft_strdup(ft_rights(perm, i, stat)));
}

void		ft_create_list(char *path)
{
	DIR				*ret;
	struct dirent	*elem;
	t_elem			*list;
	int				i;

	i = 1;
	if ((ret = opendir(path)) == NULL)
	{
		ft_putstr("opendir error\n");
		return ;
	}
	elem = readdir(ret);
	if (!(list = (t_elem *)malloc(sizeof(t_elem))))
		exit(1);
	list = NULL;
	while (elem)
	{
		list = info_in_list(list, elem->d_name, ft_strjoin(path, elem->d_name));
		elem = readdir(ret);
	}
	list = ft_sort_ascii(list);
	while (list)
	{
		//	printf("maillon %d:\n\n", i);
		printf("name: %s\n", list->name);
		/*	printf("modif_last: %lld\n", list->modif_last);
		printf("create: %ld\n", list->create);
		printf("blocks: %d\n", list->blocks);
		printf("perm: %s\n", list->perm);
		printf("links: %d\n", list->links);
		printf("user: %s\n", list->user);
		printf("group: %s\n", list->group);
		printf("is_dir: %d\n", list->is_dir);
		printf("count: %d\n", list->count);
		printf("size: %zu\n\n", list->size);*/
		i++;
		list = list->next;
	}
	closedir(ret);
}

int			main(int argc, char **argv)
{
	int			i;
	char		*path;

	i = 0;
	path = NULL;
	while (++i < argc)
	{
		path = argv[i];
		ft_create_list(path);
	}
	if (!path)
		ft_create_list("./");
	return (0);
}
