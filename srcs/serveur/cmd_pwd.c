/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 18:23:14 by rsibiet           #+#    #+#             */
/*   Updated: 2017/10/03 18:23:16 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serveur.h>
#include <unistd.h>

void	cmd_pwd(char *cmd, t_client *client)
{
	char	buf[1024];

	(void)cmd;
	if (getcwd(buf, 1024) == NULL)
		write(client->fd, "ERROR: getcwd failed.\n", 22);
	else
		write(client->fd, buf, ft_strlen(buf));
}
