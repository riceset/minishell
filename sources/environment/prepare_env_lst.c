/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_env_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:05:49 by tkomeno           #+#    #+#             */
/*   Updated: 2022/12/12 23:30:05 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void prepare_env_lst(char **envp)
{
	int i;
	char **tmp;

	i = 0;
	g_var.env_lst = env_cdll_lstinit();
	while (envp[i])
	{
		tmp = ft_split(envp[i], '=');
		env_cdll_lstadd_back(&g_var.env_lst, env_cdll_lstnew(tmp[0], tmp[1]));		
		ft_matrixfree(tmp);
		i++;
	}
}

