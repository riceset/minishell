/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recreate_envp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 23:31:28 by vkist-si          #+#    #+#             */
/*   Updated: 2022/12/12 22:55:57 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	recreate_envp(void)
{
	t_env	*trav;
	int		i;

	g_var.envp = ft_calloc(env_cdll_lstsize(g_var.env_lst), sizeof(char *));
	i = 0;
	trav = g_var.env_lst;
	while (!trav->is_sentinel)
	{
		g_var.envp[i] = join_three(trav->key, "=", trav->value);
		trav = trav->next;
		i++;
	}
	g_var.envp[i] = NULL;
	free_env_lst();
}
