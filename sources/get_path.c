/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 23:24:11 by vkist-si          #+#    #+#             */
/*   Updated: 2022/11/30 23:25:14 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cdll.h"
#include "libft.h"
#include "minishell.h"

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
