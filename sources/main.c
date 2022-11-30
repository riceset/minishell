/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:38:41 by tkomeno           #+#    #+#             */
/*   Updated: 2022/11/30 23:43:51 by vkist-si         ###   ########.fr       */
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
