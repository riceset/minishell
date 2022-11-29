/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cdll_lstinit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:20:11 by tkomeno           #+#    #+#             */
/*   Updated: 2022/11/29 18:24:35 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cdll.h"

t_env	*env_cdll_lstinit(void)
{
	t_env	*sentinel;

	sentinel = env_cdll_lstnew("", "");
	sentinel->is_sentinel = true;
	sentinel->next = sentinel;
	sentinel->prev = sentinel;
	return (sentinel);
}
