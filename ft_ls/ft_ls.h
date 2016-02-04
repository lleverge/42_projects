/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 13:25:02 by lleverge          #+#    #+#             */
/*   Updated: 2016/01/29 18:09:41 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft/libft.h"
# include <dirent.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>

int             ft_rec_list_dir(char *name);
int				ft_opendir_error(void);
int				ft_close_dir_error(void);

#endif
