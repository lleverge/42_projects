/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 13:24:16 by lleverge          #+#    #+#             */
/*   Updated: 2016/02/05 13:53:18 by lleverge         ###   ########.fr       */
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

