/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:11:05 by lleverge          #+#    #+#             */
/*   Updated: 2016/03/11 15:44:22 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_count_dir(t_elem *elem)
{
	int	i;

	i = 0;
	while (elem)
	{
		if (elem->is_dir)
			i++;
		elem = elem->next;
	}
	return (i);
}

static	void	ft_put_css(char c, char *s1, char *s2)
{
	ft_putchar(c);
	ft_putstr(s1);
	ft_putstr(s2);
}

char			*ft_add_slash(char *path)
{
	if (path[ft_strlen(path) - 1] != '/')
		path = ft_strjoin(path, "/");
	return (path);
}

void			ft_recursive(t_elem *elem, t_opt *opt, char *path, int nb_dir)
{
	char	**all_dir;
	int		i;

	i = 0;
	if (!(all_dir = (char **)malloc(sizeof(char *) * nb_dir + 1)))
		exit(1);
	all_dir[nb_dir + 1] = NULL;
	while (elem)
	{
		if (elem->is_dir == 1)
		{
			all_dir[i] = ft_strdup(elem->name);
			i++;
		}
		elem = elem->next;
	}
	i = -1;
	while (++i < nb_dir)
	{
		if (opt->a == 1 && all_dir[i][0] == '.')
			ft_put_css('\n', ft_strjoin(path, all_dir[i]), ":\n");
		else if (all_dir[i][0] != '.')
			ft_put_css('\n', ft_strjoin(path, all_dir[i]), ":\n");
		ft_create_list(ft_strjoin(path, ft_add_slash(all_dir[i])), opt);
	}
}
