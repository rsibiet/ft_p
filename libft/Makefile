# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 10:49:22 by rsibiet           #+#    #+#              #
#    Updated: 2016/03/09 15:56:05 by rsibiet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FTC = ft_memset.c \
	  ft_memdup.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  get_next_line.c \
	  ft_memccpy.c \
	  ft_switch.c \
	  ft_switch_fl.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_strlen.c \
	  ft_strdup.c \
	  ft_strdup_dup.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_strlcat.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
	  ft_atoi.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_strnew.c \
	  ft_strdel.c \
	  ft_strdel_void.c \
	  ft_strdel_del.c \
	  ft_strclr.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strjoin_join.c \
	  ft_strtrim.c \
	  ft_itoa.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putendl.c \
	  ft_putendl_endl.c \
	  ft_putnbr.c \
	  ft_putnbr_ul.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strsplit.c \
	  ft_isspace.c \
	  ft_isblank.c \
	  ft_abs.c \
	  ft_labs.c \
	  ft_iscntrl.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_itoa_hex.c \
	  ft_put_addr.c

FTO = $(subst .c,.o,$(FTC))

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(FTO)
	@ar rc $(NAME) $(FTO)
	@ranlib $(NAME)
	@echo ""
	@echo ""
	@echo "\033[32m• $(NAME) created!\033[0m"
	@echo ""
	@echo ""
	@echo "\033[0m------------------------------------------------------------------------"

%.o: %.c
	@gcc -Wall -Wextra -Werror -c $<
	@echo "\033[42m \033[0m\c"

clean:
	@rm -rf $(FTO)
	@echo "\033[33m• Libft object deleted!\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31;1m• \033[31mLibft deleted!\033[0m"

fcleana:
	@rm -rf $(FTO)
	@rm -rf $(NAME)
	@echo "\033[31;1m• \033[31mLibft deleted!\033[0m"

re: fclean all
