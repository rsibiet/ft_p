/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 14:58:46 by rsibiet           #+#    #+#             */
/*   Updated: 2017/10/04 14:58:47 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>
#include <unistd.h>

int		cmd_ls(char *cmd)
{
	char	buf[1024];
	int		r;

	if (cmd[2] != '\0' && cmd[2] != ' ')
	{
		write(1, "Unknown command\n", 16);
		return (-1);
	}
	write(save_sock(NULL, 1)->fd, cmd, ft_strlen(cmd));
	while ((r = read(save_sock(NULL, 1)->fd, buf, 1023)) > 0)
	{
		buf[r] = '\0';
		write(1, buf, r);
		if (ft_strlen(buf) > 8 && ft_strlen(buf) < 22 &&
			(ft_strnequ("\nERROR", buf, 6) == 1 ||
			ft_strnequ("\nSUCCESS", buf, 8) == 1))
			return (0);
	}
	if (r <= 0)
		put_error("ERROR: Connection lost.");
	return (0);
}
