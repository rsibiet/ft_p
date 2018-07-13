# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/27 13:28:21 by rsibiet           #+#    #+#              #
#    Updated: 2017/09/27 13:28:24 by rsibiet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = serveur
NAME2 = client

FTC1 = 	main.c \
		signaux.c \
		list_clients.c \
		cmd_pwd.c \
		cmd_ls.c \
		cmd_put.c \
		cmd_get.c \
		cmd_cd.c \
		cmd_mkdir.c

FTC2 = 	main.c \
		signaux.c \
		cmd_pwd.c \
		cmd_ls.c \
		cmd_quit.c \
		cmd_put.c \
		cmd_get.c \
		cmd_cd.c \
		bonus.c

SRC_FTC1 = $(addprefix srcs/serveur/, $(FTC1))
SRC_FTC2 = $(addprefix srcs/client/, $(FTC2))

FTO1 = $(SRC_FTC1:%.c=%.o)
FTO2 = $(SRC_FTC2:%.c=%.o)

EXEC = libft.a
.PHONY: all re clean fclean

all: $(EXEC) $(NAME1) $(NAME2)

$(EXEC):
	@echo "\033[34;1m____________________________ Loading libft _______________________________\033[0m\n"
	@make -C ./libft

$(NAME1): $(FTO1)
	@echo ""
	@echo "\033[32m• $(NAME1) created!\033[0m"
	@echo ""
	@gcc -Wall -Wextra -Werror -o $(NAME1) $(FTO1) -I ./includes/ -L./libft -lft

$(NAME2): $(FTO2)
	@echo "\033[32m• $(NAME2) created!\033[0m"
	@echo ""
	@gcc -Wall -Wextra -Werror -o $(NAME2) $(FTO2) -I ./includes/ -L./libft -lft

%.o: %.c
	@tput civis
	@gcc -Wall -Wextra -Werror -I./libft/ -I./includes/ -o $@ -c $<
	@tput cnorm

clean:
	@rm -rf $(FTO1)
	@rm -rf $(FTO2)
	@echo "\033[33m• $(NAME1) & $(NAME2) object deleted!\033[0m"

fclean: clean
	@rm -rf $(NAME1)
	@rm -rf $(NAME2)
	@echo "\033[31;1m• \033[31m$(NAME1) & $(NAME2) deleted!\033[0m"

re: fclean all
