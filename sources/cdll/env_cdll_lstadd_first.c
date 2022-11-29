/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cdll_lstadd_first.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:18:34 by tkomeno           #+#    #+#             */
/*   Updated: 2022/11/29 18:24:08 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cdll.h"

void	env_cdll_lstadd_first(t_env **head, t_env *new)
{
	new->next = *head;
	new->prev = *head;
	(*head)->next = new;
	(*head)->prev = new;
	*head = (*head)->next;
}
