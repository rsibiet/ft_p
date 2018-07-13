/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_mkdir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:26:16 by rsibiet           #+#    #+#             */
/*   Updated: 2017/10/12 17:26:20 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serveur.h>
#include <sys/types.h>
#include <sys/stat.h>

void			cmd_mkdir(char *cmd, t_client *client)
{
	char	**s;

	s = ft_strsplit(cmd, ' ');
	if (mkdir(s[1], 0755) == -1)
		write(client->fd, "ERROR: Fail to create directory.\n", 33);
	else
		write(client->fd, "SUCCESS\n", 8);
}
