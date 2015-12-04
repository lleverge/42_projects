/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:11:18 by lleverge          #+#    #+#             */
/*   Updated: 2015/12/04 16:53:50 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int		check_file(char *file_name)
{
	int		fd;
	char	buf[5];
	int		ret;
	int		i;

	fd = open(file_name,  O_RDONLY);
	if (fd == -1)
		return (1);
	while ((ret = read(fd, buf, 1)) > 0)
	{
		buf[ret] = '\0';
		printf("%s", buf);
	}
	close(fd);
	if (close(fd) == -1)
		return (1);
	return (0);
}

int		main(int argc, char  **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (check_file(argv[1]) == 1)
		return (1);
	return (0);
}
