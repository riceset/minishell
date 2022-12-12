/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_env_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:05:49 by tkomeno           #+#    #+#             */
/*   Updated: 2022/12/12 17:10:45 by tkomeno          ###   ########.fr       */
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
		if (i == 0)
			env_cdll_lstadd_first(&g_var.env_lst, env_cdll_lstnew(tmp[0], tmp[1]));
		else
			env_cdll_lstadd_back(&g_var.env_lst, env_cdll_lstnew(tmp[0], tmp[1]));
		i++;
	}
}

