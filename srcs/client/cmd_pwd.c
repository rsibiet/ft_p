/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 18:23:36 by rsibiet           #+#    #+#             */
/*   Updated: 2017/10/03 18:23:37 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>
#include <unistd.h>

int		cmd_pwd(char *cmd)
{
	char			buf[1024];
	int				r;
	int				i;

	i = 3;
	while (cmd[i] != '\0' && (cmd[i] == ' ' || cmd[i] == '\t'))
		i++;
	if (cmd[i] != '\0')
	{
		if (cmd[3] != ' ' && cmd[3] != '\t')
			write(1, "Unknown command\n", 16);
		else
			ft_putendl_fd("pwd: too many arguments.", 2);
	}
	else
	{
		write(save_sock(NULL, 1)->fd, "pwd", 3);
		if ((r = read(save_sock(NULL, 1)->fd, buf, 1022)) <= 0)
			put_error("ERROR: Connection lost.");
		buf[r] = '\n';
		buf[r + 1] = '\0';
		write(1, buf, r + 1);
		write(1, "\nSUCCESS\n", 9);
	}
	return (0);
}
