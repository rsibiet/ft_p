/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 13:29:18 by rsibiet           #+#    #+#             */
/*   Updated: 2017/09/27 13:29:20 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serveur.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>

static int		create_serveur(int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	if ((proto = getprotobyname("tcp")) == NULL)
		put_error("Getprotobyname error");
	if ((sock = socket(PF_INET, SOCK_STREAM, proto->p_proto)) == -1)
		put_error("Socket error");
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
		put_error("Bind error");
	if (listen(sock, 42) == -1)
		put_error("Listen error");
	if (getcwd(save_sock(NULL, 1)->path, 512) == NULL)
		put_error("ERROR: getcwd failed.");
	return (sock);
}

static void		point_cmd(char *cmd, t_client *client)
{
	static void (*liste_fonctions[7])(char *, t_client *) = {
		cmd_ls,
		cmd_cd,
		cmd_get,
		cmd_put,
		cmd_pwd,
		cmd_mkdir
	};

	if (ft_strnequ("ls", cmd, 2) == 1)
		liste_fonctions[LS](cmd, client);
	else if (ft_strnequ("cd", cmd, 2) == 1)
		liste_fonctions[CD](cmd, client);
	else if (ft_strnequ("get", cmd, 3) == 1)
		liste_fonctions[GET](cmd, client);
	else if (ft_strnequ("put", cmd, 3) == 1)
		liste_fonctions[PUT](cmd, client);
	else if (ft_strnequ("pwd", cmd, 3) == 1)
		liste_fonctions[PWD](cmd, client);
	else if (ft_strnequ("mkdir", cmd, 5) == 1)
		liste_fonctions[MKDIR](cmd, client);
}

static void		cmd_loop(t_client *client)
{
	int					r;
	char				buf[1024];
	unsigned int		i;

	while ((r = read(client->fd, buf, 1023)) > 0)
	{
		buf[r] = '\0';
		i = 0;
		point_cmd(buf, client);
	}
}

static int		fork_loop(t_client *client)
{
	int status;

	if ((client->pid = fork()) == 0)
	{
		ft_putendl("Connection accepted.");
		cmd_loop(client);
		close(client->fd);
		wait4(client->pid, &status, 0, NULL);
		ft_putendl("Connection closed.");
		close(save_sock(NULL, 1)->fds);
		del_client(save_sock(NULL, 1)->head);
		free(save_sock(NULL, 1));
		return (0);
	}
	else if (client->pid > 0)
		close(client->fd);
	else
		put_error("Fork error");
	return (1);
}

int				main(int ac, char **av)
{
	t_sock				*sock;
	t_client			*client;
	struct sockaddr_in	csin;
	int					fd_client;

	if ((sock = (t_sock *)ft_memalloc(sizeof(t_sock))) == NULL)
		put_error("Malloc error");
	if (ac != 2)
		usage(av[0]);
	if ((sock->port = ft_atoi(av[1])) == 0 && ft_strcmp(av[1], "0") != 0)
		usage(av[0]);
	save_sock(sock, 0);
	sock->fds = create_serveur(sock->port);
	ft_signal();
	while (42)
	{
		if ((fd_client = accept(sock->fds, (struct sockaddr *)&csin,
			&(sock->cslen))) == -1)
			put_error("accept error");
		client = new_client(fd_client);
		if (fork_loop(client) == 0)
			return (0);
	}
	return (0);
}
