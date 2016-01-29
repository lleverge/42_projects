/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 17:00:42 by lleverge          #+#    #+#             */
/*   Updated: 2016/01/29 17:05:25 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_opendir_error(void)
{
	ft_putstr_fd("opendirerror\n", 2);
	return (-1);
}

int		ft_closedir_error(void)
{
	ft_putstr_fd("closedirerror\n", 2);
	return (-1);
}
