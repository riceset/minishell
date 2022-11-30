/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_envr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 23:01:09 by vkist-si          #+#    #+#             */
/*   Updated: 2022/11/30 23:03:06 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cdll.h"
#include "libft.h"
#include "minishell.h"

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
