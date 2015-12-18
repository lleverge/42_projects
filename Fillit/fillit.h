/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:35:48 by lleverge          #+#    #+#             */
/*   Updated: 2015/12/18 11:06:51 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "srcs/libft.h"
# include <fcntl.h>
# define BUF_SIZE 546

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
char					**pieces_intab(char *file_name);
t_tetri					*tetri_lstnew(char *piece, char let);
int						count_offsety(char *piece);
int						count_offsetx(char *piece);
int						count_width(char *piece);
int						count_height(char *piece);
t_tetri					*piece_inlist(int piece_nbr, char **tab);
int						resolve(t_tetri *list, char *map);
int						place_piece(t_tetri tetri, char *map);
void					ft_error(void);
char					*ft_read_file(char *file);
int						ft_check_file(char *s);
int						ft_count_tetri(char *s);
int						ft_count_char(char *s, char c);

#endif
