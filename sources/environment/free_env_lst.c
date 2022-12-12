/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:06:41 by tkomeno           #+#    #+#             */
/*   Updated: 2022/12/12 17:38:33 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cdll.h"
#include "minishell.h"

void free_env_lst(void)
{
	t_env *env_lst;
	t_env *trv;

	env_lst = g_var.env_lst;
	while (!env_lst->is_sentinel)
	{
		trv = env_lst;
		env_lst = env_lst->next;
		free(trv->key);
		free(trv->value);
		free(trv);
	}
}
