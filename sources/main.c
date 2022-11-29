/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:38:41 by tkomeno           #+#    #+#             */
/*   Updated: 2022/11/29 19:42:54 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cdll.h"
#include "libft.h"
#include "minishell.h"

void	void_caster(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;
}

char	**tokenizer(char *line)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	return (tokens);
}

char	*read_line(void)
{
	char	*line;

	line = readline("minishell$ ");
	add_history(line);
	return (line);
}

t_env	*prepare_environment(char **envp)
{
	int		i;
	char	**tmp;
	t_env	*env_lst;

	i = 0;
	env_lst = env_cdll_lstinit();
	while (envp[i])
	{
		tmp = ft_split(envp[i], '=');
		if (i == 0)
			env_cdll_lstadd_first(&env_lst, env_cdll_lstnew(tmp[0], tmp[1]));
		else
			env_cdll_lstadd_back(&env_lst, env_cdll_lstnew(tmp[0], tmp[1]));
		i++;
	}
	return (env_lst);
}

void	append_slash_to_path(char **paths)
{
	int	i;

	i = -1;
	while (paths[++i])
		paths[i] = ft_strjoin(paths[i], "/");
}

char	**get_paths(t_env *env_lst)
{
	char	*path;
	char	**paths;

	while (!env_lst->is_sentinel)
	{
		if (ft_strncmp(env_lst->key, "PATH", 5) == 0)
			path = env_lst->value;
		env_lst = env_lst->next;
	}
	paths = ft_split(path, ':');
	append_slash_to_path(paths);
	return (paths);
}

char	*find_command(char *command, char **paths)
{
	int		i;
	char	*tmp;
	char	*path;

	path = NULL;
	if (access(command, F_OK | X_OK) == 0)
		return (command);
	i = -1;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], command);
		if (access(tmp, F_OK | X_OK) == 0)
		{
			path = tmp;
			break ;
		}
		free(tmp);
	}
	return (path);
}

void	exec_command(char *line, char **tokens)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(line, tokens, NULL) == -1)
			printf("minishell: command not found.\n");
	}
	else
		waitpid(pid, &status, 0);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	char	**tokens;
	char	**paths;
	t_env	*env_lst;

	void_caster(argc, argv, envp);
	env_lst = prepare_environment(envp);
	paths = get_paths(env_lst);
	while (true)
	{
		line = read_line();
		tokens = tokenizer(line);
		line = find_command(tokens[0], paths);
		exec_command(line, tokens);
	}
	return (0);
}
