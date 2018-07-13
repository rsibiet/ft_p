/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_quit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 18:33:34 by rsibiet           #+#    #+#             */
/*   Updated: 2017/10/04 18:33:35 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

int		cmd_quit(char *cmd)
{
	if (ft_strlen(cmd) > 4 && ft_strnequ("quit", cmd, 4) == 1)
		write(1, "Unknown command\n", 16);
	if (ft_strlen(cmd) == 4 && ft_strnequ("quit", cmd, 4) == 1)
	{
		ft_strdel(&cmd);
		return (1);
	}
	else
	{
		ft_strdel(&cmd);
		return (0);
	}
}

int		cmd_other(char *cmd)
{
	(void)cmd;
	write(1, "Unknown command\n", 16);
	return (0);
}
