/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 16:03:47 by rsibiet           #+#    #+#             */
/*   Updated: 2017/10/10 16:03:48 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>
#include <fcntl.h>

int				error_getcmd(char **s, char *cmd, char buf[1024], int r)
{
	int			fd_file;

	if (s[1] == NULL || s[2] != NULL)
	{
		ft_putendl_fd("ERROR: usage: <get> <name file>", 2);
		ft_strdel_del(&s);
		return (-1);
	}
	write(save_sock(NULL, 1)->fd, cmd, ft_strlen(cmd));
	if ((r = read(save_sock(NULL, 1)->fd, buf, 1023)) <= 0)
		put_error("\nERROR: Connection lost.");
	if (ft_strnequ("READY", buf, 5) == 0)
	{
		ft_strdel_del(&s);
		write(1, buf, r);
		return (-1);
	}
	if ((fd_file = open(s[1], O_RDWR | O_CREAT, S_IRWXU | S_IRGRP)) == -1)
	{
		ft_strdel_del(&s);
		write(save_sock(NULL, 1)->fd, "FAIL", 4);
		ft_putendl_fd("\nERROR: fail to create the file.", 2);
		return (-1);
	}
	return (fd_file);
}

static int		error_cdcmd(char **s)
{
	if (ft_strlen(s[0]) != 2)
	{
		ft_strdel_del(&s);
		write(1, "Unknown command\n", 16);
		return (-1);
	}
	if (s[1] != NULL && s[2] != NULL)
	{
		ft_putendl_fd("ERROR: usage: <cd> <path>", 2);
		ft_strdel_del(&s);
		return (-1);
	}
	ft_strdel_del(&s);
	return (0);
}

int				cmd_cd(char *cmd)
{
	char		buf[1024];
	int			r;
	char		**s;
	int			i;

	s = ft_strsplit(cmd, ' ');
	i = 0;
	if (error_cdcmd(s) == -1)
		return (-1);
	write(save_sock(NULL, 1)->fd, cmd, ft_strlen(cmd));
	if ((r = read(save_sock(NULL, 1)->fd, buf, 1022)) <= 0)
		put_error("ERROR: Connection lost.");
	if (ft_strnequ("ERROR: ", buf, 7) == 1)
		write(1, buf, r);
	else
	{
		while (i < r)
		{
			save_sock(NULL, 1)->path[i] = buf[i];
			i++;
		}
		save_sock(NULL, 1)->path[i] = '\0';
		ft_putendl("SUCCESS");
	}
	return (0);
}
