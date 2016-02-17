/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:12:50 by lleverge          #+#    #+#             */
/*   Updated: 2016/02/16 14:02:12 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_display_l(t_elem *list, int blocks, t_pad *pad, t_opt *options)
{
  if (options->l == 1)
    {
      ft_putstr("total ");
      ft_putnbr(blocks);
      ft_putchar('\n');
      ft_padding(&list, pad);
    }
  while (list)
    {
      if (options->a == 1)
	{
	  print_infos(list, options);
	  ft_putchar('\n');
	}
      else
	{
	  if (REAL_DIR(list->name))
	    {
	      print_infos(list, options);
	      ft_putchar('\n');
	    }
	}
      list = list->next;
    }
}


t_elem		*ft_index_list(t_elem *elem)
{
  t_elem	*tmp;
  int		i;

  tmp = elem;
  i = 0;
  while (tmp)
    {
      tmp->count = i;
      i++;
      tmp = tmp->next;
    }
  return (elem);
}
