/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 18:54:29 by rsibiet           #+#    #+#             */
/*   Updated: 2017/10/04 18:54:31 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

static int		error_putcmd(char **s, int fd_file)
{
	if (s[1] == NULL || s[2] != NULL)
	{
		ft_putendl_fd("ERROR: usage: <put> <name file>", 2);
		ft_strdel_del(&s);
		return (-1);
	}
	if ((fd_file = open(s[1], O_RDONLY)) == -1)
	{
		ft_putendl("ERROR: Fail to open the file.");
		ft_strdel_del(&s);
		return (-1);
	}
	ft_strdel_del(&s);
	return (fd_file);
}

static void		display_bar(long long total, long long rest)
{
	int		i;
	int		val;

	i = 0;
	if (total == rest)
	{
		ft_putstr("\033[34;1m__________________________ Upload ");
		ft_putendl("__________________________\033[0m\n");
	}
	ft_putchar('\r');
	val = (total - rest) * 60 / total + 1;
	if (save_sock(NULL, 1)->bar == 0)
		save_sock(NULL, 1)->bar = val;
	if (val == save_sock(NULL, 1)->bar)
		return ;
	save_sock(NULL, 1)->bar = val;
	while (i < val)
	{
		ft_putstr("\e[47m \033[0m");
		i++;
	}
	ft_putnbr(val * 100 / 60);
	ft_putchar('%');
	if (val == 60)
		write(1, "\n\n", 2);
}

static int		stream_put(long long size, long long r, int fd_file,
							char buf[1024])
{
	long long	total_size;

	total_size = size;
	if (size == 0)
		write(save_sock(NULL, 1)->fd, "_EMPTY_FILE_", 12);
	while (size > 0 && (r = read(fd_file, buf, 1023)) > 0)
	{
		if (total_size > 1000000)
			display_bar(total_size, size);
		write(save_sock(NULL, 1)->fd, buf, r);
		size -= r;
		if ((size > 0 || total_size == 1023) &&
			(r = read(save_sock(NULL, 1)->fd, buf, 1023)) <= 0)
			put_error("ERROR: Connection lost.");
		if (size > 0 && ft_strnequ("_NEXT_", buf, 6) == 0)
		{
			write(1, buf, r);
			close(fd_file);
			return (-2);
		}
		if (total_size == 1023)
			write(save_sock(NULL, 1)->fd, "_END_OF_FILE_", 13);
	}
	close(fd_file);
	return (r);
}

static int		init_stream(char *cmd, int fd_file, t_stat *stat)
{
	long long	r;
	char		buf[128];

	if (fstat(fd_file, stat) == -1)
	{
		close(fd_file);
		ft_putendl("ERROR: Fail to fstat on the file.");
		return (-1);
	}
	write(save_sock(NULL, 1)->fd, cmd, ft_strlen(cmd));
	if ((r = read(save_sock(NULL, 1)->fd, buf, 127)) <= 0)
		put_error("\nERROR: Connection lost.");
	if (ft_strnequ("READY", buf, 5) == 0)
	{
		write(1, buf, r);
		close(fd_file);
		return (-1);
	}
	return (0);
}

int				cmd_put(char *cmd)
{
	char		**s;
	int			fd_file;
	char		buf[1024];
	long long	r;
	t_stat		stat;

	s = ft_strsplit(cmd, ' ');
	if ((fd_file = error_putcmd(s, 0)) == -1)
		return (-1);
	if (init_stream(cmd, fd_file, &stat) == -1)
		return (-1);
	save_sock(NULL, 1)->bar = 0;
	if ((r = stream_put(stat.st_size, 0, fd_file, buf)) == -1)
		ft_putendl("\nERROR: Fail to read the file.");
	else if (r != -2)
	{
		if ((r = read(save_sock(NULL, 1)->fd, buf, 1023)) <= 0)
			put_error("\nERROR: Connection lost.");
		write(1, buf, r);
	}
	return (0);
}
