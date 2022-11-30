/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:38:41 by tkomeno           #+#    #+#             */
/*   Updated: 2022/11/30 17:59:53 by tkomeno          ###   ########.fr       */
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

void	exec_command(char *line, char **tokens, char **envp)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		if (execve(line, tokens, envp) == -1)
			perror("minishell");
	}
	else
		waitpid(pid, &status, 0);
}

char	*join_three(char *s1, char *s2, char *s3)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin(s1, s2);
	tmp2 = ft_strjoin(tmp, s3);
	free(tmp);
	return (tmp2);
}

char	**recreate_envp(t_env *env_lst)
{
	char	**envp;
	char	*current_line;
	t_env	*trav;
	int i;

	envp = ft_calloc(env_cdll_lstsize(env_lst), sizeof(char *));
	i = 0;
	trav = env_lst;
	while (!trav->is_sentinel)
	{
		current_line = join_three(trav->key, "=", trav->value);
		envp[i] = current_line;
		trav = trav->next;
		i++;
	}
	envp[i] = NULL;
	return (envp);
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
	signal(SIGINT, SIG_DFL);
	while (true)
	{
		line = read_line();
		tokens = tokenizer(line);
		line = find_command(tokens[0], paths);
		envp = recreate_envp(env_lst);
		exec_command(line, tokens, envp);
	}
	return (0);
}
