/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cdll_lstsize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:14:52 by tkomeno           #+#    #+#             */
/*   Updated: 2022/11/30 14:23:03 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cdll.h"

size_t env_cdll_lstsize(t_env *head)
{
	size_t size;
	t_env *trav;

	size = 0;
	trav = head;
	while (!trav->is_sentinel)
	{
		size++;
		trav = trav->next;
	}
	return (size);
}
