/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:12:50 by lleverge          #+#    #+#             */
/*   Updated: 2016/02/10 14:20:02 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_display_l(t_elem *list, int blocks, t_pad *pad)
{
	ft_putstr("total ");
    ft_putnbr(blocks);
    ft_putchar('\n');
    ft_padding(&list, pad);
    while (list)
    {
        print_infos(list);
        ft_putchar('\n');
        list = list->next;
    }
}
