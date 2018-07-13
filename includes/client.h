/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 13:28:39 by rsibiet           #+#    #+#             */
/*   Updated: 2017/09/27 13:28:40 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "../libft/libft.h"

# define LIST_CMD cmd_ls,cmd_cd,cmd_get,cmd_put,cmd_pwd,cmd_quit,cmd_other
# define LIST_CMD_BONUS cmd_lpwd, cmd_lls, cmd_lcd, cmd_mkdir

typedef struct stat	t_stat;

typedef enum		e_cmd
{
	LS,
	CD,
	GET,
	PUT,
	PWD,
	QUIT,
	OTHER,
	LPWD,
	LLS,
	LCD,
	MKDIR
}					t_cmds;

typedef struct		s_sock
{
	int				fd;
	int				port;
	char			path[1024];
	int				bar;
}					t_sock;

/*
**	bonus file
*/
int					cmd_mkdir(char *cmd);
int					cmd_lcd(char *cmd);
int					cmd_lpwd(char *cmd);
int					cmd_lls(char *cmd);

/*
**	cmd_cd file
*/
int					error_getcmd(char **s, char *cmd, char buf[1024], int r);
int					cmd_cd(char *cmd);

/*
**	cmd_get file
*/
int					cmd_get(char *cmd);

/*
**	cmd_put file
*/
int					cmd_put(char *cmd);

/*
**	cmd_quit file
*/
int					cmd_quit(char *cmd);
int					cmd_other(char *cmd);

/*
**	cmd_ls file
*/
int					cmd_ls(char *cmd);

/*
**	cmd_pwd file
*/
int					cmd_pwd(char *cmd);

/*
**	signaux file
*/
void				put_error(char *err);
t_sock				*save_sock(t_sock *sock, int i);
void				ft_signal(void);

#endif
