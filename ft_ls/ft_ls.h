/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 13:25:02 by lleverge          #+#    #+#             */
/*   Updated: 2016/02/10 09:21:21 by lleverge         ###   ########.fr       */
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
	int				R;
	int				r;
	int				t;
}					t_opt;

typedef struct		s_elem
{
	char			*name;
	long long		modif_last;
	time_t			create;
	int				blocks;
	char			*perm;
	int				links;
	char			*user;
	char			*group;
	int				is_dir;
	int				count;
	size_t			size;
	struct s_elem	*next;
}					t_elem;

typedef struct stat t_stat;

t_elem				*info_in_list(t_elem *start, char *fname, char *path);
char				*ft_rights(char *perm, int i, t_stat *stat);
char				*ft_perm(t_stat *stat);
void				ft_create_list(char *path);
void				get_infos(char *fname, t_elem *tmp, t_stat stat);
#endif
