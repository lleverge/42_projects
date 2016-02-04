/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 18:07:03 by lleverge          #+#    #+#             */
/*   Updated: 2016/01/29 19:17:25 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "libft/libft.h"
#include <pwd.h>

int main(int argc, char **argv)
{
	struct stat		file_stat;
	struct passwd	*pwd;
	struct group	*guid;

	if (argc != 2)    
		return 1;
	if (stat(argv[1],&file_stat) < 0)    
		return 1;
	ft_putstr((S_ISDIR(file_stat.st_mode)) ? "d" : "-");
	ft_putstr((file_stat.st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((file_stat.st_mode & S_IWUSR) ? "w" : "-");
	ft_putstr((file_stat.st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr((file_stat.st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr((file_stat.st_mode & S_IWGRP) ? "w" : "-");
	ft_putstr((file_stat.st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr((file_stat.st_mode & S_IROTH) ? "r" : "-");
	ft_putstr((file_stat.st_mode & S_IWOTH) ? "w" : "-");
	ft_putstr((file_stat.st_mode & S_IXOTH) ? "x" : "-");
	ft_putchar(' ');
	if ((pwd = getpwuid(file_stat.st_uid)) != NULL)
		ft_putstr(pwd->pw_name);
	if ((guid = getgrgid(file_stat.)
	ft_putchar(' ');
	ft_putnbr(file_stat.st_size);
	ft_putchar(' ');
	ft_putstr(argv[1]);
    return 0;
}
