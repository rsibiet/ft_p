/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 16:03:55 by rsibiet           #+#    #+#             */
/*   Updated: 2017/10/10 16:03:56 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serveur.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

static int		cmd_cd2(char oldpath[512], char **s, t_client *client)
{
	char	*path;

	if ((path = s[1]) == NULL || ft_strcmp(s[1], "~") == 0)
		path = save_sock(NULL, 1)->path;
	if (getcwd(oldpath, 1024) == NULL)
	{
		write(client->fd, "ERROR: getcwd failed.\n", 22);
		ft_strdel_del(&s);
		return (-1);
	}
	if ((chdir(path)) == -1)
	{
		write(client->fd, "ERROR: Unable to go to specified directory\n", 43);
		ft_strdel_del(&s);
		return (-1);
	}
	ft_strdel_del(&s);
	return (0);
}

static char		*strsub_cd(char const *s, unsigned int start, size_t len)
{
	char	*cp;
	size_t	i;

	i = 1;
	cp = (char *)malloc(sizeof(*s) * len + 3);
	if (cp == NULL)
		return (NULL);
	cp[0] = '~';
	while (i < len + 1)
	{
		cp[i] = s[start];
		start++;
		i++;
	}
	cp[i] = '\0';
	return (cp);
}

void			cmd_cd(char *cmd, t_client *client)
{
	char	**s;
	char	npath[1024];
	char	oldpath[1024];
	char	*tosend;

	s = ft_strsplit(cmd, ' ');
	if (cmd_cd2(oldpath, s, client) == -1)
		return ;
	if (getcwd(npath, 1024) == NULL)
		write(client->fd, "ERROR: getcwd failed.\n", 22);
	else if (ft_strnequ(save_sock(NULL, 1)->path, npath,
		ft_strlen(save_sock(NULL, 1)->path)) == 1)
	{
		tosend = strsub_cd(npath, ft_strlen(save_sock(NULL, 1)->path),
			ft_strlen(npath));
		write(client->fd, tosend, ft_strlen(tosend));
		ft_strdel(&tosend);
	}
	else
	{
		chdir(oldpath);
		write(client->fd, ER_DIR, 61);
	}
}
