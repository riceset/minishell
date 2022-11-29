/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cdll_lstadd_back.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:19:30 by tkomeno           #+#    #+#             */
/*   Updated: 2022/11/29 18:25:27 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cdll.h"

void	env_cdll_lstadd_back(t_env **head, t_env *new)
{
	t_env	*tail;
	t_env	*sentinel;

	if ((*head)->is_sentinel)
	{
		env_cdll_lstadd_first(head, new);
		return ;
	}
	tail = (*head)->prev->prev;
	sentinel = (*head)->prev;
	new->next = sentinel;
	new->prev = tail;
	sentinel->prev = new;
	tail->next = new;
}
