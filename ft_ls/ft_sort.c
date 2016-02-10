/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 09:38:40 by lleverge          #+#    #+#             */
/*   Updated: 2016/02/10 09:53:23 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_elem			*ft_elem_swap(t_elem *elem1, t_elem *elem2)
{
	elem1->next = elem2->next;
	elem2->next = elem1;
	return (elem2);
}

t_elem			*ft_sort_ascii(t_elem *elem)
{
	if (elem == NULL)
		return (NULL);
	if (elem->next != NULL && ft_strcmp(elem->name, elem->next->name) > 0)
		elem = ft_elem_swap(elem, elem->next);
	elem->next = ft_sort_ascii(elem->next);
	if (elem->next != NULL && ft_strcmp(elem->name, elem->next->name) > 0)
	{
		elem = ft_elem_swap(elem, elem->next);
		elem->next = ft_sort_ascii(elem->next);
	}
	return (elem);
}
