# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 20:31:52 by tkomeno           #+#    #+#              #
#    Updated: 2022/12/01 19:17:04 by tkomeno          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell
LIBFT_PATH	=	./libraries/libft
LIBS_PATH 	= 	-L$(LIBFT_PATH)
LIBS		=	-lft -lreadline
INCLUDES	=	-I ./includes -I $(LIBFT_PATH)/includes
CFLAGS		=	-Wall -Wextra -Werror $(INCLUDES)
FILES 		=	1_initialize/main.c \
				1_initialize/init_envr.c \
				1_initialize/prompt.c \
				2_tokenizer/tokenizer.c \
				3_execution/exec.c \
				3_execution/get_cmd.c \
				utils/get_path.c \
				utils/join_three.c \
				utils/restaure_envp.c \
				utils/linked_list/env_cdll_lstadd_back.c \
				utils/linked_list/env_cdll_lstadd_first.c \
				utils/linked_list/env_cdll_lstadd_front.c \
				utils/linked_list/env_cdll_lstclear.c \
				utils/linked_list/env_cdll_lstinit.c \
				utils/linked_list/env_cdll_lstnew.c \
				utils/linked_list/env_cdll_lstsize.c
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
