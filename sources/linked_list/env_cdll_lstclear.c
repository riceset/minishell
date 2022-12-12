/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cdll_lstclear.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:21:55 by tkomeno           #+#    #+#             */
/*   Updated: 2022/12/12 23:53:59 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cdll.h"

void	env_cdll_lstclear(t_env **head)
{
	t_env *to_free;
	t_env *trav;

	to_free = *head;

	while (!to_free->is_sentinel)
	{
		trav = to_free->next;
		free(to_free);
		to_free = trav;
	}
	free(to_free);
}
