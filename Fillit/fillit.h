/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:35:48 by lleverge          #+#    #+#             */
/*   Updated: 2015/12/16 15:00:13 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "srcs/libft.h"
# include <fcntl.h>

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

char					*ft_cattetri(char **tab, int start, int end);
char					**pieces_tab(char *file_name);
t_tetri					*tetri_lstnew(char *piece, char let);
int						count_offsety(char *piece);
int						count_offsetx(char *piece);
int						count_width(char *piece);
int						count_height(char *piece);
#endif
