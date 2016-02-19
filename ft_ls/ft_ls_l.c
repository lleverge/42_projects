/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 18:07:03 by lleverge          #+#    #+#             */
/*   Updated: 2016/02/19 17:39:01 by lleverge         ###   ########.fr       */
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
	tmp->links = ft_itoa(stat.st_nlink);
	tmp->is_dir = (tmp->perm[0] == 'd' && REAL_DIR(tmp->name));
	tmp->size = ft_itoa(stat.st_size);
	tmp->device = stat.st_rdev;
	tmp->min = ft_strdup(ft_itoa(minor(tmp->device)));
	tmp->maj = ft_strdup(ft_itoa(major(tmp->device)));
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

void		print_infos(t_elem *list, t_opt *options)
{
	if (options->l == 1)
	{
		ft_putstr(list->perm);
		ft_putstr("  ");
		ft_putstr(list->links);
		ft_putchar(' ');
		ft_putstr(list->user);
		ft_putstr("  ");
		ft_putstr(list->group);
		ft_putstr("  ");
		ft_print_majmin(list);
		ft_putchar(' ');
		ft_putstr(ft_strsub(ctime(&list->create), 4, 12));
		ft_putchar(' ');
	}
	ft_putstr(list->name);
}

int			count_blocks(t_elem *list)
{
	int	count;

	count = 0;
	while (list != NULL)
	{
		count += list->blocks;
		list = list->next;
	}
	return (count);
}
