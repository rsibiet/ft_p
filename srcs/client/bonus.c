/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 14:15:59 by rsibiet           #+#    #+#             */
/*   Updated: 2017/10/12 14:16:01 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>
#include <unistd.h>
#include <fcntl.h>

int				cmd_mkdir(char *cmd)
{
	int		i;
	char	buf[128];
	int		r;

	i = 5;
	while (cmd[i] != '\0' && cmd[i] == ' ')
		i++;
	if (i == 5 && ft_strlen(cmd) > 5)
	{
		write(1, "Unknown command\n", 16);
		return (-1);
	}
	while (cmd[i] != '\0' && cmd[i] != ' ')
		i++;
	if (ft_strlen(cmd) < 7 || cmd[i] != '\0')
	{
		ft_putendl_fd("ERROR: usage: <mkdir> <dirname>", 2);
		return (-1);
	}
	write(save_sock(NULL, 1)->fd, cmd, ft_strlen(cmd));
	if ((r = read(save_sock(NULL, 1)->fd, buf, 127)) <= 0)
		put_error("ERROR: Connection lost.");
	write(1, buf, r);
	return (0);
}

static int		error_lcdcmd(char **s)
{
	if (ft_strlen(s[0]) != 3)
	{
		ft_strdel_del(&s);
		write(1, "Unknown command\n", 16);
		return (-1);
	}
	if (s[1] == NULL || s[2] != NULL)
	{
		ft_putendl_fd("ERROR: usage: <lcd> <path>", 2);
		ft_strdel_del(&s);
		return (-1);
	}
	return (0);
}

int				cmd_lcd(char *cmd)
{
	char		**s;

	s = ft_strsplit(cmd, ' ');
	if (error_lcdcmd(s) == -1)
		return (-1);
	if ((chdir(s[1])) == -1)
	{
		ft_putendl("ERROR: Unable to go to specified directory.");
		ft_strdel_del(&s);
		return (-1);
	}
	write(1, "\nSUCCESS\n", 9);
	ft_strdel_del(&s);
	return (0);
}

int				cmd_lpwd(char *cmd)
{
	char			buf[1024];
	int				i;

	i = 4;
	while (cmd[i] != '\0' && (cmd[i] == ' ' || cmd[i] == '\t'))
		i++;
	if (cmd[i] != '\0')
	{
		if (cmd[4] != ' ' && cmd[4] != '\t')
			write(1, "Unknown command\n", 16);
		else
			ft_putendl_fd("lpwd: too many arguments.", 2);
	}
	else
	{
		if (getcwd(buf, 1024) == NULL)
			ft_putendl("ERROR: getcwd failed.");
		else
			ft_putendl(buf);
		write(1, "\nSUCCESS\n", 9);
	}
	return (0);
}

int				cmd_lls(char *cmd)
{
	pid_t		pid;
	char		**param;
	int			status;

	param = ft_strsplit(cmd, ' ');
	if (cmd[3] != '\0' && cmd[3] != ' ')
		write(1, "Unknown command\n", 16);
	else if ((pid = fork()) == -1)
		ft_putendl("\nERROR: fork error.");
	else if (pid == 0)
	{
		execv("/bin/ls", param);
		ft_putendl("\nERROR: Execv error.");
		wait4(pid, &status, 0, NULL);
	}
	else
	{
		wait4(pid, &status, 0, NULL);
		write(1, "\nSUCCESS\n", 9);
	}
	ft_strdel_del(&param);
	return (0);
}
