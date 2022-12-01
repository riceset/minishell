/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:38:41 by tkomeno           #+#    #+#             */
/*   Updated: 2022/12/01 19:32:03 by tkomeno          ###   ########.fr       */
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
		tokens = tokenizer(line);
		line = find_command(tokens[0], paths);
		envp = recreate_envp(env_lst);
		exec_command(line, tokens, envp);
	}
	return (0);
}
