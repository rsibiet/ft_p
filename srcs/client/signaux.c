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

#include <client.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>

void			put_error(char *err)
{
	t_sock		*sock;

	if ((sock = save_sock(NULL, 1)) != NULL)
	{
		close(sock->fd);
		free(sock);
	}
	ft_putendl_fd(err, 2);
	exit(EXIT_FAILURE);
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
	if (i == SIGINT || i == SIGQUIT || i == SIGTSTP)
	{
		close(save_sock(NULL, 1)->fd);
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
