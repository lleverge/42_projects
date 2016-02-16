/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:12:00 by lleverge          #+#    #+#             */
/*   Updated: 2016/02/16 14:27:01 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_detect_opt(char **argv, int argc, t_opt *options)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
	}
}

void	init_opt(t_opt *options)
{
	options->l = 0;
	options->a = 0;
	options->rec = 0;
	options->r = 0;
	options->t = 0;
}
