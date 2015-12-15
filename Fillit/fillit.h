/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:35:48 by lleverge          #+#    #+#             */
/*   Updated: 2015/12/15 11:08:57 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct			s_tetri
{
	char				*tetri;
	int					width;
	int					height;
	int					offsetx;
	int					offsety;
	char				letter;
	struct s_tetri		*next;
}						t_tetri;

char					*ft_cattetri(char **tab, int start_index, int end_index);
char					**pieces_tab(char *file_name);

#endif
