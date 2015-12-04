/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:11:18 by lleverge          #+#    #+#             */
/*   Updated: 2015/12/04 17:10:25 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int			ft_strlen(char *str)
{
	int		count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

void		ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int			check_file(char *file_name)
{
	int		fd;
	char	buf[5];
	int		ret;
	int		i;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (1);
	while ((ret = read(fd, buf, 1)) > 0)
	{
		if (*buf != '.' && *buf != '#')
			return (1);
	}
	close(fd);
	if (close(fd) == -1)
		return (1);
	return (0);
}

int			main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("error\n");
		return (0);
	}
	if (check_file(argv[1]) == 1)
	{
		ft_putstr("error\n");
		return (1);
	}
	return (0);
}
