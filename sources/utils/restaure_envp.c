/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restaure_envp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 23:31:28 by vkist-si          #+#    #+#             */
/*   Updated: 2022/12/01 19:20:48 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**recreate_envp(t_env *env_lst)
{
	char	**envp;
	char	*current_line;
	t_env	*trav;
	int		i;

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
