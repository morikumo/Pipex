# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabid <mabid@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/01 13:46:38 by morikumo          #+#    #+#              #
#    Updated: 2022/06/18 19:42:35 by mabid            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	= srcs/pipex.c srcs/utils.c srcs/error.c \
		  srcs/ft_chara.c srcs/ft_putstr_fd.c \
		  srcs/ft_split.c srcs/ft_fin_de_phrase.c \
		  srcs/ft_strjoindre.c srcs/ft_strnstr.c \
		  srcs/ft_strlen.c \

OBJS			= $(SRCS:.c=.o)

NAME			= pipex

CFLAGS			= -Wall -Wextra -Werror -g

RM				= rm -f

CC				= gcc

AR				= ar rcs

.c.o:
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) 

$(NAME):		$(OBJS)
				@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L.
				@echo -ne '\033[32m                            (0%)\r'
				@sleep 0.2
				@echo -ne '#####                      (33%)\r'
				@sleep 0.2
				@echo -ne '#############              (66%)\r'
				@sleep 0.2
				@echo -ne '#######################   (100%)\r'
				@echo -ne '\n'
				@echo "\033[33mC'est compilé !"

all:			$(NAME)

clean:
				@$(RM) $(OBJS)
				@echo -ne '\033[36m#######################   (100%)\r'
				@sleep 0.2
				@echo -ne '#############              (66%)\r'
				@sleep 0.2
				@echo -ne '#####                      (33%)\r'
				@sleep 0.2
				@echo -ne '                            (0%)\r'
				@echo -ne '\n'
				@echo "\033[33mC'est clean !"

fclean:			clean
				@$(RM) $(NAME) 
				@echo -ne '\033[34m#######################   (100%)\r'
				@sleep 0.2
				@echo -ne '#############              (66%)\r'
				@sleep 0.2
				@echo -ne '#####                      (33%)\r'
				@sleep 0.2
				@echo -ne '                            (0%)\r'
				@echo -ne '\n'
				@echo "\033[33mC'est fclean !"

re:				fclean all

normin:			
	norminette	./srcs ./libft pipex.h

wnormin: 		
	watch norminette	./srcs ./libft pipex.h

.PHONY:	all clean fclean c.o re
