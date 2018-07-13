/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:45:24 by rsibiet           #+#    #+#             */
/*   Updated: 2017/10/09 17:45:26 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serveur.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

static int		cmd_get3(long long *size, int r, int fd_file, t_client *client)
{
	t_stat		stat;
	char		buf[128];

	if (fstat(fd_file, &stat) == -1)
	{
		write(client->fd, "ERROR: Fail fstat on the file\n", 30);
		return (-1);
	}
	write(client->fd, "READY", 5);
	if ((r = read(client->fd, buf, 127)) <= 0)
	{
		write(client->fd, "ERROR: Connection lost.\n", 24);
		return (-1);
	}
	if (ft_strnequ("CREATED", buf, 127) == 0)
		return (-1);
	if ((*size = stat.st_size) == 0)
	{
		write(client->fd, "_EMPTY_FILE_", 12);
		return (0);
	}
	return (r);
}

static void		cmd_get2(t_client *client, int fd_file)
{
	char		buf[1024];
	int			r;
	long long	size;

	size = 0;
	if ((r = cmd_get3(&size, 0, fd_file, client)) == -1)
		return ;
	while (size > 0 && (r = read(fd_file, buf, 1023)) > 0)
	{
		write(client->fd, buf, r);
		if (size == 1023)
			write(client->fd, "_END_OF_FILE_", 13);
		size -= r;
	}
	if (r < 0)
		write(client->fd, "ERROR: Fail to read the file\n", 29);
}

void			cmd_get(char *cmd, t_client *client)
{
	char		**s;
	int			fd_file;

	s = ft_strsplit(cmd, ' ');
	if ((fd_file = open(s[1], O_RDONLY)) == -1)
	{
		write(client->fd, "ERROR: Fail to open the file\n", 29);
		ft_strdel_del(&s);
		return ;
	}
	ft_strdel_del(&s);
	cmd_get2(client, fd_file);
	close(fd_file);
}
