/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 18:54:38 by rsibiet           #+#    #+#             */
/*   Updated: 2017/10/04 18:54:39 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serveur.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

static int		size_stream(int size, t_client *client)
{
	t_stat		stat;
	int			i;

	i = 0;
	while (size == 0)
	{
		if (fstat(client->fd, &stat) == -1)
		{
			write(client->fd, "\nERROR: Fail fstat on the file.\n", 32);
			return (-2);
		}
		size = stat.st_size;
		if (i >= 5000000)
		{
			ft_putendl("ERROR: Upload stopped.");
			return (-2);
		}
		i++;
	}
	return (size);
}

static int		stream_put(int size, t_client *client,
							int fd_file, char buf[1024])
{
	int			r;

	while (size > 0 && (r = read(client->fd, buf, 1023)) > 0)
	{
		if (size == 12 && ft_strnequ("_EMPTY_FILE_", buf, 12) == 1)
			return (1);
		else if (r == 13 && ft_strnequ("_END_OF_FILE_", buf, 13) == 1)
			return (1);
		write(fd_file, buf, r);
		size -= r;
		if (r == 1023)
		{
			write(client->fd, "_NEXT_", 6);
			if ((size = size_stream(0, client)) == -2)
				return (-2);
		}
	}
	return (r);
}

void			cmd_put(char *cmd, t_client *client)
{
	char		**s;
	int			fd_file;
	char		buf[1024];
	int			r;
	t_stat		stat;

	s = ft_strsplit(cmd, ' ');
	if ((fd_file = open(s[1], O_RDWR | O_CREAT, S_IRWXU | S_IRGRP)) == -1)
	{
		write(client->fd, "\nERROR: fail to create the file.\n", 33);
		return ;
	}
	ft_strdel_del(&s);
	if (fstat(client->fd, &stat) == -1)
	{
		write(client->fd, "\nERROR: Fail fstat on the file\n", 31);
		return ;
	}
	write(client->fd, "READY", 5);
	if ((r = stream_put(size_stream(0, client), client, fd_file, buf)) == -1)
		write(client->fd, "\nERROR: fail to read file.\n", 27);
	else if (r != -2)
		write(client->fd, "SUCCESS\n", 8);
	close(fd_file);
}
