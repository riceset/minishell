/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cdll_lstnew.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:14:07 by tkomeno           #+#    #+#             */
/*   Updated: 2022/12/01 19:28:56 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cdll.h"

t_env	*env_cdll_lstnew(char *key, char *value)
{
	t_env	*new;

	new = ft_calloc(1, sizeof(t_env));
	if (!new)
		return (NULL);
	new->key = key;
	new->value = value;
	new->is_sentinel = FALSE;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
