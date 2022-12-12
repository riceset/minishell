/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:30:39 by tkomeno           #+#    #+#             */
/*   Updated: 2022/12/12 17:31:53 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_paths(void)
{
	int	i;

	i = -1;
	while (g_var.paths[++i])
		free(g_var.paths[i]);
	free(g_var.paths);
}
