/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:23:34 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/01/24 13:06:09 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	read_next_file(char *file)
{
	int		fd;
	char	*line;
	int		res;

	res = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("oups, an error occured while OPENING your file: ");
		ft_putendl(file);
		return (1);
	}
	else
		ft_putstr("cool, everything's FINE \n");
	while (res == get_next_line(fd, &line))
	{
		if (res == -1)
		{
			ft_putstr("oups, an error occured while GETTING next line in your file: ");
			ft_putendl(file);
			return (1);
		}
		else
			ft_putendl(line);
	}
	if (close(fd) == -1)
	{
		ft_putstr("oups, an error occurend while CLOSING your file: ");
		ft_putendl(file);
		return (1);
	}	
	return (0);
}

int	main(int argc, char **argv)
{
	int i;
	
	i = 1;
	if (argc <= 1)
		ft_putendl("oups, your source files are MISSING");
	while (i < argc)
	{
		if (read_next_file(argv[i]))
			return (1);
		i++;
	}
	return (0);
}
