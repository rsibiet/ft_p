/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 13:28:47 by rsibiet           #+#    #+#             */
/*   Updated: 2017/09/27 13:28:49 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVEUR_H
# define SERVEUR_H

# include <unistd.h>
# include "../libft/libft.h"

# define ER_DIR "ERROR: You can't access to a lower level of main directory.\n"

typedef struct stat		t_stat;

typedef enum			e_cmd
{
	LS,
	CD,
	GET,
	PUT,
	PWD,
	MKDIR
}						t_cmds;

typedef struct			s_client
{
	int					fd;
	pid_t				pid;
	struct s_client		*next;
}						t_client;

typedef struct			s_sock
{
	t_client			*head;
	int					fds;
	int					port;
	unsigned int		cslen;
	char				path[512];
}						t_sock;

/*
**	cmd_mkdir file
*/
void					cmd_mkdir(char *cmd, t_client *client);

/*
**	cmd_cd file
*/
void					cmd_cd(char *cmd, t_client *client);

/*
**	cmd_get file
*/
void					cmd_get(char *cmd, t_client *client);

/*
**	cmd_put file
*/
void					cmd_put(char *cmd, t_client *client);

/*
**	cmd_ls file
*/
void					cmd_ls(char *cmd, t_client *client);

/*
**	cmd_pwd file
*/
void					cmd_pwd(char *cmd, t_client *client);

/*
**	signaux file
*/
void					usage(char *str);
t_sock					*save_sock(t_sock *sock, int i);
void					ft_signal(void);

/*
**	list_clients file
*/
void					put_error(char *err);
void					del_client(t_client *lst);
void					delone_client(t_client **lst, t_client *node);
t_client				*new_client(int fd);

#endif
