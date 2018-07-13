/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_clients.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 12:57:04 by rsibiet           #+#    #+#             */
/*   Updated: 2017/10/03 12:57:08 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serveur.h>
#include <stdlib.h>

void			put_error(char *err)
{
	t_client			*client;
	int					status;
	t_sock				*sock;

	if ((sock = save_sock(NULL, 1)) != NULL)
	{
		close(sock->fds);
		client = sock->head;
		while (client != NULL)
		{
			close(client->fd);
			wait4(client->pid, &status, 0, NULL);
			client = client->next;
		}
	}
	del_client(sock->head);
	free(sock);
	ft_putendl_fd(err, 2);
	exit(EXIT_FAILURE);
}

void			del_client(t_client *lst)
{
	while (lst != NULL)
		delone_client(&lst, lst);
}

void			delone_client(t_client **lst, t_client *node)
{
	if (!node)
		return ;
	if (save_sock(NULL, 1)->head == node)
		save_sock(NULL, 1)->head = node->next;
	if (lst && *lst)
		*lst = node->next;
	ft_bzero(node, sizeof(t_client));
	ft_memdel((void **)&node);
}

t_client		*new_client(int fd)
{
	t_client	*new;
	t_client	*prev;

	prev = save_sock(NULL, 1)->head;
	while (prev != NULL && prev->next != NULL)
		prev = prev->next;
	if ((new = (t_client *)ft_memalloc(sizeof(t_client))) == NULL)
		exit(EXIT_FAILURE);
	if (prev != NULL)
		prev->next = new;
	else
		save_sock(NULL, 1)->head = new;
	new->fd = fd;
	return (new);
}
