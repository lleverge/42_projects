/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:48:18 by lleverge          #+#    #+#             */
/*   Updated: 2016/02/16 13:07:17 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	no_file_dir(char *fname)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_putstr("ft_ls: ");
	while (fname[i])
		i++;
	while (j < i - 1)
	{
		ft_putchar(fname[j]);
		j++;
	}
	perror(" ");
	return ;
}
