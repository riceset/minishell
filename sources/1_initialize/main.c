/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:38:41 by tkomeno           #+#    #+#             */
/*   Updated: 2022/12/06 19:30:52 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	char	**tokens;
	char	**paths;
	t_env	*env_lst;

	if (argc > 1 || !argv[0])
		return (1);
	env_lst = prepare_environment(envp);
	paths = get_paths(env_lst);
	while (TRUE)
	{
		line = read_line();
		envp = recreate_envp(env_lst);
		tokens = tokenizer(line);
		line = find_command(tokens[0], paths);
		if (ft_strcmp(tokens[0], line) == 0)
		{
			error_handler(line, "command not found");
			continue;
		}
		exec_command(line, tokens, envp);
	}
	return (0);
}
