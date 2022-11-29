/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cdll_lstclear.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:21:55 by tkomeno           #+#    #+#             */
/*   Updated: 2022/11/29 18:24:19 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cdll.h"

void	env_cdll_lstclear(t_env **head)
{
	t_env	*temp;
	t_env	*trav;

	trav = *head;
	while (!trav->is_sentinel)
	{
		temp = trav->next;
		free(trav);
		trav = temp;
	}
	free(trav);
	*head = trav;
}
