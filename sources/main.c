/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:38:41 by tkomeno           #+#    #+#             */
/*   Updated: 2022/11/29 18:54:19 by tkomeno          ###   ########.fr       */
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

int	main(int argc, char **argv, char **envp)
{
	t_env *env_lst;

	void_caster(argc, argv, envp);
	env_lst = prepare_environment(envp);

	for (t_env *tmp = env_lst; !tmp->is_sentinel; tmp = tmp->next)
		printf("%s : %s\n", tmp->key, tmp->value);

	return (0);
}
// int	main(int argc, char **argv, char **envp)
// {
// 	char *line;
// 	char **tokens;
// 	char *path;

// 	void_caster(argc, argv, envp);

// 	while (true)
// 	{
// 		line = read_line();
// 		tokens = tokenizer(line);
// 	}
// 	return (0);
// }
