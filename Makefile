# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 20:31:52 by tkomeno           #+#    #+#              #
#    Updated: 2022/11/30 23:44:29 by vkist-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell
LIBFT_PATH	=	./libraries/libft
LIBS_PATH 	= 	-L$(LIBFT_PATH)
LIBS		=	-lft -lreadline
INCLUDES	=	-I ./includes -I $(LIBFT_PATH)/includes
CFLAGS		=	-Wall -Wextra -Werror $(INCLUDES)
FILES 		=	main.c \
				init_envr.c \
				get_path.c \
				restaure_envp.c \
				get_cmd.c \
				cdll/env_cdll_lstadd_back.c \
				cdll/env_cdll_lstadd_first.c \
				cdll/env_cdll_lstadd_front.c \
				cdll/env_cdll_lstclear.c \
				cdll/env_cdll_lstinit.c \
				cdll/env_cdll_lstnew.c \
				cdll/env_cdll_lstsize.c
SRCS		=	$(addprefix sources/, $(FILES))
OBJS		=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) --no-print-directory
	$(CC) $(OBJS) -o $(NAME) $(LIBS_PATH) $(LIBS)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT_PATH) --no-print-directory

fclean:
	$(RM) $(OBJS) $(NAME)
	$(MAKE) fclean -C $(LIBFT_PATH) --no-print-directory

re: fclean all

.PHONY: all clean fclean re
