/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:07:04 by tkomeno           #+#    #+#             */
/*   Updated: 2022/12/12 17:10:48 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_env_lst(void)
{
	t_env *trv;

	trv = g_var.env_lst;
	while (!trv->is_sentinel)
	{
		printf("%s=%s\n", trv->key, trv->value);
		trv = trv->next;
	}
}

