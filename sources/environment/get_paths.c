/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:20:46 by tkomeno           #+#    #+#             */
/*   Updated: 2022/12/12 23:57:15 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	append_slash_to_paths(char **paths)
{
	int	i;

	i = -1;
	while (paths[++i])
		paths[i] = ft_strjoin(paths[i], "/");
}

void	get_paths()
{
	t_env	*env_lst;
	char	*path;

	env_lst = g_var.env_lst;
	while (!env_lst->is_sentinel)
	{
		if (ft_strcmp(env_lst->key, "PATH") == 0)
			path = env_lst->value;
		env_lst = env_lst->next;
	}
	g_var.paths = ft_split(path, ':');
	append_slash_to_paths(g_var.paths);
}
