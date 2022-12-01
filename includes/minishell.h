/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:39:16 by tkomeno           #+#    #+#             */
/*   Updated: 2022/12/01 19:44:42 by tkomeno          ###   ########.fr       */
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

typedef struct s_token
{
	struct s_token *prev;
	struct s_token *next;
} t_token;

t_env	*prepare_environment(char **envp);
char	**get_paths(t_env *env_lst);
char	**recreate_envp(t_env *env_lst);
char	*find_command(char *command, char **paths);
char	*read_line(void);
void	exec_command(char *line, char **tokens, char **envp);
char	**tokenizer(char *line);
char	*join_three(char *s1, char *s2, char *s3);
char	**ft_split_by_set(char *str, char *charset);

#endif
