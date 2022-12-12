/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:26:38 by tkomeno           #+#    #+#             */
/*   Updated: 2022/12/12 17:26:53 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_paths(void)
{
	int i;

	i = -1;
	while (g_var.paths[++i])
		printf("%s\n", g_var.paths[i]);
}
