/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 13:25:02 by lleverge          #+#    #+#             */
/*   Updated: 2016/02/19 17:21:51 by lleverge         ###   ########.fr       */
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
	size_t			min;
	size_t			maj;
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
	dev_t			device;
	char			*min;
	char			*maj;
	struct s_elem	*next;
}					t_elem;

typedef struct stat	t_stat;

char				*ft_add_slash(char *path);
int					ft_count_dir(t_elem *elem);
void				ft_recursive(t_elem *elem, t_opt *opt, char *path, int nb_dir);
void				ft_print_majmin(t_elem *list);
t_elem				*ft_index_list(t_elem *elem);
t_elem				*ft_sort_rev(t_elem *elem);
void				opt_error(char *s);
void				ft_detect_opt(char *arg, t_opt *options);
void				init_opt(t_opt *options);
void				no_file_dir(char *fname);
void				ft_padding(t_elem **elem, t_pad *pad);
int					count_blocks(t_elem *list);
void				print_infos(t_elem *list, t_opt *options);
t_elem				*ft_sort_time(t_elem *elem);
t_elem				*ft_sort_ascii(t_elem *elem);
t_elem				*info_in_list(t_elem *start, char *fname, char *path);
char				*ft_rights(char *perm, int i, t_stat *stat);
char				*ft_perm(t_stat *stat);
void				ft_create_list(char *path, t_opt *options);
void				get_infos(char *fname, t_elem *tmp, t_stat stat);
t_elem				*ft_elem_swap(t_elem *elem1, t_elem *elem2);
void				display_l(t_elem *list, int block, t_pad *pad, t_opt *opt);
void				ft_display(t_elem *elem, t_opt *options, t_pad *pad, char *path);
#endif
