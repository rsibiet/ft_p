/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:45:04 by rsibiet           #+#    #+#             */
/*   Updated: 2017/10/02 18:45:05 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serveur.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>

void			usage(char *str)
{
	printf("Usage: %s <port>\n", str);
	exit(-1);
}

t_sock			*save_sock(t_sock *sock, int i)
{
	static t_sock		*tmp = NULL;

	if (i == 0)
		tmp = sock;
	return (tmp);
}

static void		read_signal(int i)
{
	t_client	*client;
	int			status;

	client = save_sock(NULL, 1)->head;
	if (i == SIGINT || i == SIGQUIT || i == SIGTSTP)
	{
		close(save_sock(NULL, 1)->fds);
		while (client != NULL)
		{
			close(client->fd);
			wait4(client->pid, &status, 0, NULL);
			client = client->next;
		}
		del_client(save_sock(NULL, 1)->head);
		free(save_sock(NULL, 1));
		exit(EXIT_SUCCESS);
	}
}

void			ft_signal(void)
{
	int		i;

	i = 1;
	while (i < 28)
	{
		signal(i, read_signal);
		i++;
	}
}
