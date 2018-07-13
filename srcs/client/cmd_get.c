/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:45:17 by rsibiet           #+#    #+#             */
/*   Updated: 2017/10/09 17:45:19 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

static int			stream_get(char buf[1024], int r, int *fd_file)
{
	if (r < 31 && ft_strnequ("ERROR: ", buf, 7) == 1)
	{
		close(*fd_file);
		write(1, buf, r);
		return (-1);
	}
	else if (r == 13 && ft_strnequ("_END_OF_FILE_", buf, 13) == 1)
		return (1);
	write(*fd_file, buf, r);
	return (0);
}

static int			size_stream(long long size, int fd_file)
{
	t_stat		stat;
	int			i;

	i = 0;
	while (size == 0)
	{
		if (fstat(save_sock(NULL, 1)->fd, &stat) == -1)
		{
			if (fd_file != -1)
				close(fd_file);
			ft_putendl_fd("\nERROR: Fail fstat on the file.", 2);
			return (-1);
		}
		size = stat.st_size;
		if (i >= 5000000)
		{
			put_error("\nERROR: Connection lost. Download stopped.");
			return (-1);
		}
		i++;
	}
	return (size);
}

static int			close_stream(int r, int fd_file)
{
	close(fd_file);
	if (r == -1)
		ft_putendl_fd("\nERROR: fail to read file.", 2);
	else
		ft_putendl("SUCCESS");
	return (0);
}

static long long	init_stream(char buf[1024], int fd_file)
{
	long long	size;
	int			r;

	size = 0;
	write(save_sock(NULL, 1)->fd, "CREATED", 7);
	if ((r = read(save_sock(NULL, 1)->fd, buf, 1023)) <= 0)
		put_error("\nERROR: Connection lost.");
	if (r == 1023 && (size = size_stream(0, fd_file)) == -1)
		return (-1);
	if (ft_strnequ("_EMPTY_FILE_", buf, 12) == 1)
		return (0);
	else if (r < 31 && ft_strnequ("ERROR: ", buf, 7) == 1)
	{
		close(fd_file);
		write(1, buf, r);
		return (-1);
	}
	write(fd_file, buf, r);
	return (size);
}

int					cmd_get(char *cmd)
{
	char		**s;
	char		buf[1024];
	int			r[2];
	long long	size;
	int			fd_file;

	s = ft_strsplit(cmd, ' ');
	if ((fd_file = error_getcmd(s, cmd, buf, 0)) == -1)
		return (-1);
	ft_strdel_del(&s);
	if ((size = init_stream(buf, fd_file)) == -1)
		return (-1);
	while (size > 0 && (r[0] = read(save_sock(NULL, 1)->fd, buf, 1023)) > 0)
	{
		if ((r[1] = stream_get(buf, r[0], &fd_file)) == -1)
			return (-1);
		else if (r[1] == 1)
			break ;
		size -= r[0];
		if (r[0] == 1023 && (size = size_stream(0, fd_file)) == -1)
			return (-1);
	}
	return (close_stream(r[0], fd_file));
}
