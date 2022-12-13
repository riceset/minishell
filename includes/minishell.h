/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:39:16 by tkomeno           #+#    #+#             */
/*   Updated: 2022/12/12 17:56:50 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "cdll.h"
# include "libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_var
{
	char		*line;
	t_env		*env_lst;
	char		**envp;
	char		**paths;
	char		**tokens;
}				t_var;

extern t_var	g_var;

void			prepare_env_lst(char **envp);
void			free_env_lst(void);
void			print_env_lst(void);
void			get_paths(void);
void			print_paths(void);
void			read_line(void);
char			*join_three(char *s1, char *s2, char *s3);
void			recreate_envp(void);

#endif
