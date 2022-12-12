/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cdll_lstadd_front.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:18:54 by tkomeno           #+#    #+#             */
/*   Updated: 2022/11/29 18:25:33 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cdll.h"

void	env_cdll_lstadd_front(t_env **head, t_env *new)
{
	t_env	*sentinel;

	if ((*head)->is_sentinel)
	{
		env_cdll_lstadd_first(head, new);
		return ;
	}
	sentinel = (*head)->prev;
	new->next = *head;
	new->prev = sentinel;
	(*head)->prev = new;
	sentinel->next = new;
}
