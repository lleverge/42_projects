/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:02:34 by lleverge          #+#    #+#             */
/*   Updated: 2016/03/11 17:16:47 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_get_time(const long *f_time)
{
	char	*tmp;
	char	*prev;
	char	*new;
	time_t	today;

	time(&today);
	tmp = ctime(f_time);
	if (today - 15724800 > *f_time || today < *f_time)
	{
		prev = ft_strsub(tmp, 4, 7);
		new = ft_strjoin(prev, ft_strsub(tmp, 20, 24));
		new[ft_strlen(new)] = '\0';
		ft_strdel(&prev);
	}
	else
		new = ft_strsub(tmp, 4, 12);
	if (ft_strchr(new, '\n'))
		(ft_strchr(new, '\n'))[0] = '\0';
	return (new);
}

char		*ft_lastword(char *s)
{
	char	*ptr;
	int		is_word;

	ptr = NULL;
	is_word = 0;
	while (*s)
	{
		if (!ft_isspace(*s) && !is_word)
		{
			ptr = s;
			is_word = 1;
		}
		else if (ft_isspace(*s))
			is_word = 0;
		++s;
	}
	return (ptr);
}
