/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recreate_envp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guribeir <guribeir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 23:31:28 by vkist-si          #+#    #+#             */
/*   Updated: 2022/12/12 17:53:09 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	recreate_envp(void)
{
	char	*current_line;
	t_env	*trav;
	int		i;

	g_var.envp = ft_calloc(env_cdll_lstsize(g_var.env_lst), sizeof(char *));
	i = 0;
	trav = g_var.env_lst;
	while (!trav->is_sentinel)
	{
		current_line = join_three(trav->key, "=", trav->value);
		g_var.envp[i] = current_line;
		trav = trav->next;
		i++;
	}
	g_var.envp[i] = NULL;
}
