# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 20:31:52 by tkomeno           #+#    #+#              #
#    Updated: 2022/12/12 17:43:30 by tkomeno          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell
LIBFT_PATH	=	./libraries/libft
LIBS_PATH 	= 	-L$(LIBFT_PATH)
LIBS		=	-lft -lreadline
INCLUDES	=	-I ./includes -I $(LIBFT_PATH)/includes
CFLAGS		=	-Wall -Wextra -Werror $(INCLUDES)
FILES 		=	main.c \
				environment/prepare_env_lst.c \
				environment/free_env_lst.c \
				environment/print_env_lst.c \
				environment/get_paths.c \
				environment/print_paths.c \
				line_handling/read_line.c \
				linked_list/env_cdll_lstadd_back.c \
				linked_list/env_cdll_lstadd_first.c \
				linked_list/env_cdll_lstadd_front.c \
				linked_list/env_cdll_lstclear.c \
				linked_list/env_cdll_lstinit.c \
				linked_list/env_cdll_lstnew.c \
				linked_list/env_cdll_lstsize.c
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
