/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 14:58:36 by rsibiet           #+#    #+#             */
/*   Updated: 2017/10/04 14:58:38 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serveur.h>
#include <unistd.h>

void	cmd_ls(char *cmd, t_client *client)
{
	pid_t		pid;
	char		**param;
	int			status;

	param = ft_strsplit(cmd, ' ');
	if ((pid = fork()) == -1)
	{
		ft_strdel_del(&param);
		write(client->fd, "\nERROR: fork error.\n", 20);
	}
	else if (pid == 0)
	{
		dup2(client->fd, 1);
		dup2(client->fd, 2);
		execv("/bin/ls", param);
		ft_strdel_del(&param);
		write(client->fd, "\nERROR: Execv error.\n", 21);
		wait4(pid, &status, 0, NULL);
	}
	else
	{
		ft_strdel_del(&param);
		wait4(pid, &status, 0, NULL);
		write(client->fd, "\nSUCCESS\n", 9);
	}
}
