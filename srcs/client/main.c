/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 13:29:09 by rsibiet           #+#    #+#             */
/*   Updated: 2017/09/27 13:29:10 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

static void		usage(char *str)
{
	printf("Usage: %s <machine> <port>\n", str);
	exit(-1);
}

static int		create_client(char *addr, int port)
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
	if (ft_strequ("localhost", addr) == 1)
		sin.sin_addr.s_addr = inet_addr("127.0.0.1");
	else
		sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
		put_error("Connect error");
	return (sock);
}

static int		point_cmd(char *cmd, int tmp)
{
	static int (*liste_fonctions[11])(char *) = {
		LIST_CMD,
		LIST_CMD_BONUS
	};

	if (ft_strnequ("ls", cmd, 2) == 1)
		liste_fonctions[LS](cmd);
	else if (ft_strnequ("cd", cmd, 2) == 1)
		liste_fonctions[CD](cmd);
	else if (ft_strnequ("get ", cmd, 4) == 1)
		liste_fonctions[GET](cmd);
	else if (ft_strnequ("put ", cmd, 4) == 1)
		liste_fonctions[PUT](cmd);
	else if (ft_strnequ("pwd", cmd, 3) == 1)
		liste_fonctions[PWD](cmd);
	else if (ft_strnequ("lpwd", cmd, 4) == 1)
		liste_fonctions[LPWD](cmd);
	else if (ft_strnequ("lls", cmd, 3) == 1)
		liste_fonctions[LLS](cmd);
	else if (ft_strnequ("lcd", cmd, 3) == 1)
		liste_fonctions[LCD](cmd);
	else if (tmp == 0 && ft_strnequ("quit", cmd, 4) == 0)
		liste_fonctions[OTHER](cmd);
	return (liste_fonctions[QUIT](cmd));
}

static int		loop_cmd(int ret)
{
	unsigned int	i;
	char			*cmd;
	char			buf[1024];

	i = 0;
	ft_putstr("\e[96mft_p ");
	ft_putstr(save_sock(NULL, 1)->path);
	ft_putstr(" > \e[39m");
	if ((ret = read(0, buf, 1023)) > 0)
	{
		buf[ret] = '\0';
		while (buf[i] == ' ' || buf[i] == '\t')
			i++;
		cmd = ft_strsub(buf, i, ret - i - 1);
		if (ft_strnequ("mkdir", cmd, 5) == 1)
			cmd_mkdir(cmd);
		return (point_cmd(cmd, ft_strnequ("mkdir", cmd, 5)));
	}
	else if (ret < 0)
		return (-1);
	return (0);
}

int				main(int ac, char **av)
{
	t_sock				*sock;

	if ((sock = (t_sock *)ft_memalloc(sizeof(t_sock))) == NULL)
		put_error("Malloc error");
	if (ac != 3)
		usage(av[0]);
	if ((sock->port = ft_atoi(av[2])) == 0 && ft_strcmp(av[1], "0") != 0)
		usage(av[0]);
	save_sock(sock, 0);
	sock->fd = create_client(av[1], sock->port);
	ft_signal();
	sock->path[0] = '~';
	sock->path[1] = '\0';
	while (loop_cmd(0) == 0)
		;
	close(sock->fd);
	free(sock);
	return (0);
}
