/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 13:25:02 by lleverge          #+#    #+#             */
/*   Updated: 2016/02/16 14:14:41 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft/libft.h"
# include <dirent.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <stdlib.h>
# include <grp.h>
# include <time.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>

# define REAL_DIR(x) (ft_strcmp(x, "..") != 0 && ft_strcmp(x, ".") != 0)

typedef struct		s_opt
{
	int				l;
	int				a;
	int				rec;
	int				r;
	int				t;
}					t_opt;

typedef struct		s_pad
{
	size_t			links;
	size_t			uid;
	size_t			gid;
	size_t			size;
}					t_pad;

typedef struct		s_elem
{
	char			*name;
	long long		modif_last;
	time_t			create;
	int				blocks;
	char			*perm;
	char			*links;
	char			*user;
	char			*group;
	int				is_dir;
	int				count;
	char			*size;
	struct s_elem	*next;
}					t_elem;

typedef struct stat	t_stat;

void				init_opt(t_opt *options);
void				no_file_dir(char *fname);
void				ft_padding(t_elem **elem, t_pad *pad);
int					count_blocks(t_elem *list);
void				print_infos(t_elem *list);
t_elem				*ft_sort_time(t_elem *elem);
t_elem				*ft_sort_ascii(t_elem *elem);
t_elem				*info_in_list(t_elem *start, char *fname, char *path);
char				*ft_rights(char *perm, int i, t_stat *stat);
char				*ft_perm(t_stat *stat);
void				ft_create_list(char *path);
void				get_infos(char *fname, t_elem *tmp, t_stat stat);
t_elem				*ft_elem_swap(t_elem *elem1, t_elem *elem2);
void				ft_display_l(t_elem *list, int blocks, t_pad *pad);
void				ft_display(t_elem *elem, t_opt *options, t_pad *pad);
#endif
